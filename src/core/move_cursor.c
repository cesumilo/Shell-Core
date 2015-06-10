/*
** move_cursor.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Apr 29 19:10:24 2015 Guillaume ROBIN
** Last update Sun May 24 14:14:48 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include "core.h"
#include "tools.h"
#include "const.h"

int	out_c(int c)
{
  return (write(STDOUT, &c, 1));
}

int	reset_cursor(t_core *core, int pos)
{
  char	*str_tgoto;
  char	*cap;

  if (tgetent(NULL, core->name_term) == ERROR)
    return (my_puterr(ERR_GTERM));
  if ((cap = tgetstr(RESET_CURSOR, NULL)) == NULL)
    return (my_puterr(ERR_CHCAP));
  if ((str_tgoto = tgoto(cap, 0, pos)) == NULL)
    return (my_puterr(ERR_TGOTO));
  if (tputs(str_tgoto, 1, &out_c) == ERROR)
    return (my_puterr(ERR_TPUTS));
  return (NO_ERR);
}

int	move_cursor_left(t_core *core)
{
  char	*cap;

  if (tgetent(NULL, core->name_term) == ERROR)
    return (my_puterr(ERR_GTERM));
  if ((cap = tgetstr(MOVE_CURSOR_LF, NULL)) == NULL)
    return (my_puterr(ERR_LECAP));
  if (tputs(cap, 1, &out_c) == ERROR)
    return (my_puterr(ERR_TPUTS));
  return (NO_ERR);
}
