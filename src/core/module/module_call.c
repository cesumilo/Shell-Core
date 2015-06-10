/*
** module_call.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core/parser
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri May  8 11:55:56 2015 Guillaume ROBIN
** Last update Wed Jun 10 14:10:38 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "core.h"
#include "parser.h"
#include "const.h"
#include "tools.h"

static t_op_tok	g_tokens[NB_TOK_FINAL] =
  {
    {TOK_SCCHV, &simple_close_chevron_operation},
    {TOK_DCCHV, &double_close_chevron_operation},
    {TOK_SOCHV, &simple_open_chevron_operation},
    {TOK_DOCHV, &double_open_chevron_operation},
    {TOK_PIPE, &pipe_operation},
    {TOK_SEMICOLON, &semicolon_operation},
    {TOK_AND, &and_operation},
    {TOK_OR, &or_operation}
  };

static int     	execute_token(t_core *core, char *token, t_mod_pack *packet,
			      t_module *mods)
{
  int		i;

  i = 0;
  while (i < NB_TOK_FINAL && str_cmp(token, g_tokens[i].token) != EQUAL)
    i++;
  if (i < NB_TOK_FINAL && g_tokens[i].op != NULL)
    return (g_tokens[i].op(core, packet, mods));
  return (ERROR);
}

int	execute_cmd(t_core *core, t_mod_pack *packet, t_module *mods)
{
  int	i;
  int  	ret;

  i = 0;
  while (mods && mods[i].start != NULL)
    {
      packet->id = i;
      while (mods && mods[i].start != NULL && mods[i].is_enabled == FALSE)
	i++;
      if (mods && mods[i].start != NULL)
	{
	  ret = mods[i].start(packet);
	  i++;
	}
      if (packet->err == ERR_FOUND)
	return (NO_ERR);
      else if (packet->err == ERR_SHUTDOWN)
	{
	  core->shutdown = DEF_SHUTDOWN(ret);
	  return (NO_ERR);
	}
      else if (packet->err != ERR_NOT_FOUND)
	return (my_puterr(ERR_MODULE));
    }
  my_puterr(ERR_42SH);
  my_puterr(packet->av[0]);
  my_puterr(ERR_END_CMD);
  return (mods && mods[i].start == NULL ? ERROR : NO_ERR_0);
}

static void	start_packet(t_core *core, t_mod_pack *packet)
{
  packet->p_write = FALSE;
  packet->p_read = FALSE;
  packet->data = core->mods;
  packet->rd_write = ERROR;
  packet->rd_read = ERROR;
  packet->fd_read = ERROR;
  packet->is_dchv = FALSE;
  packet->is_alias = FALSE;
  packet->free_needed = FALSE;
  packet->jobs = &(core->jobs);
}

static void	init_packet(t_core *core, t_mod_pack *packet, char **cmd,
			    t_btree *tmp)
{
  packet->err = NO_ERR_0;
  if (cmd != NULL)
    packet->ac = cut_tab_size(cmd);
  else
    packet->ac = 0;
  packet->av = cmd;
  packet->env = env_convert(core->env);
  packet->env_list = &(core->env);
  if (packet->p_write == TRUE)
    {
      packet->fd_read = packet->pipe[PIPEREAD];
      packet->p_read = TRUE;
      packet->p_write = FALSE;
    }
  if ((packet->rd_read != ERROR || packet->is_dchv == TRUE)
      && (str_cmp(tmp->cmd[0], TOK_SCCHV) == EQUAL
	  || str_cmp(tmp->cmd[0], TOK_DCCHV) == EQUAL))
    {
      core->err_open = open_file(get_fd(packet, tmp->cmd[0]),
				 tmp->right->cmd[0],
				 get_flags(tmp->cmd[0]),
				 get_mode(tmp->cmd[0]));
      core->jump = TRUE;
    }
}

void		module_call(t_core *core, t_btree *root)
{
  t_mod_pack	pack;
  t_btree	*tmp;
  int		ret;

  tmp = root;
  start_packet(core, &pack);
  while (!core->shutdown && tmp != NULL)
    {
      if (tmp->left != NULL)
	{
	  init_packet(core, &pack, tmp->left->cmd, tmp);
	  ret = execute_token(core, (tmp->cmd)[0], &pack, core->mods);
	}
      else
	{
	  init_packet(core, &pack, tmp->cmd, tmp);
	  ret = execute_cmd(core, &pack, core->mods);
	}
      free(pack.env);
      tmp = manage_module_call(core, ret, tmp);
    }
}
