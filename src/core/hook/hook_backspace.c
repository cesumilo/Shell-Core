/*
** backspace_hook.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Apr 30 09:49:48 2015 Guillaume ROBIN
** Last update Sun May 24 14:21:22 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include "core.h"
#include "tools.h"
#include "const.h"

int	backspace_hook(t_core *core, const char *buffer)
{
  if (buffer[0] == BACKSPACE && str_len(core->buf_caps) > 0)
    {
      core->buf_caps[str_len(core->buf_caps) - 1] = END_STR;
      if (move_cursor_left(core) == ERROR)
	my_puterr(ERR_MVCURSOR);
      put_str(SPACE_STR);
      if (move_cursor_left(core) == ERROR)
	my_puterr(ERR_MVCURSOR);
      return (TRUE);
    }
  return (FALSE);
}
