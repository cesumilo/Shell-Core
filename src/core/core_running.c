/*
** core_running.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Apr 29 17:19:51 2015 Guillaume ROBIN
** Last update Wed Jun 10 14:10:58 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <unistd.h>
#include "core.h"
#include "tools.h"
#include "const.h"
#include "parser.h"
#include "module.h"

static void	init_packet_free(t_mod_pack *packet)
{
  packet->err = ERR_FREE;
  packet->ac = 0;
  packet->env_list = NULL;
  packet->eof = NULL;
  packet->data = NULL;
  packet->av = NULL;
  packet->env = NULL;
}

static void	module_free(t_core *core)
{
  t_mod_pack	packet;
  int		i;

  init_packet_free(&packet);
  i = 0;
  while (core->mods && (core->mods)[i].start != NULL)
    {
      core->mods[i].start(&packet);
      i++;
    }
}

int	core_run_termcap(t_core *core)
{
  int	ret;
  char	buffer[BUF_CAPS_SIZE];

  put_str(PROMPT_1(core->prompt));
  while (!core->shutdown && (ret = read(0, buffer, 3)) > 0)
    {
      clear_buffer_caps(buffer, ret);
      if (key_hook(core, buffer) == FALSE)
	core->buf_caps = str_cat(core->buf_caps, buffer, FREE_LEFT);
      clear_buffer_caps(buffer, BUF_CAPS_SIZE);
      if (!core->shutdown && !reset_cursor(core, 0))
	return (ERROR);
      core->prompt = get_prompt(core);
      if (!core->shutdown)
	put_str(PROMPT_1(core->prompt));
      put_str(core->buf_caps);
    }
  free(core->buf_caps);
  free(core->prompt);
  module_free(core);
  return (NO_ERR);
}

int	core_run_no_termcap(t_core *core)
{
  int	ret;

  clear_buffer(core->buffer, 0);
  put_str(BASE_PROMPT);
  while (!core->shutdown && (ret = read(0, core->buffer, BUFF_SIZE)) > 0)
    {
      clear_buffer(core->buffer, ret - 1);
      parser(core, core->buffer);
      if (!core->shutdown)
	put_str(BASE_PROMPT);
      clear_buffer(core->buffer, 0);
    }
  free(core->prompt);
  module_free(core);
  return (NO_ERR);
}
