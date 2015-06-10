/*
** module_double_open_chevron.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core/module
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue May 12 13:16:03 2015 Guillaume ROBIN
** Last update Sun May 24 15:21:52 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <unistd.h>
#include "core.h"
#include "const.h"
#include "tools.h"
#include "get_next_line.h"

static void	get_data(t_mod_pack *packet)
{
  char		*str;
  int		ret;
  int		clear;

  ret = TRUE;
  clear = 0;
  if (packet->eof != NULL)
    {
      put_str(PROMPT_2);
      while (ret != ERROR && (str = get_next_line(STDIN, &clear))
	     && str_cmp(str, packet->av[0]) != 0)
	{
	  ret = put_str_fd(packet->pipe[PIPEWRITE], str);
	  if (ret != ERROR)
	    ret = put_str_fd(packet->pipe[PIPEWRITE], BACKSPACE_STR);
	  free(str);
	  put_str(PROMPT_2);
	}
      free(str);
    }
}

int	double_open_chevron_operation(t_core *core, t_mod_pack *packet,
					t_module *mods)
{
  if (core == NULL || mods == NULL || packet->av == NULL)
    return (ERROR);
  if (pipe(packet->pipe) == ERROR)
    {
      packet->p_read = FALSE;
      packet->p_write = FALSE;
      my_puterr(ERR_PIPE);
      return (ERROR);
    }
  packet->p_read = TRUE;
  get_data(packet);
  if (close(packet->pipe[PIPEWRITE]) == ERROR)
    my_puterr(ERR_CLOSE);
  packet->fd_read = packet->pipe[PIPEREAD];
  packet->is_dchv = TRUE;
  return (NO_ERR);
}
