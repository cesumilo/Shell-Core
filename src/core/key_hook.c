/*
** key_hook.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Apr 29 20:07:12 2015 Guillaume ROBIN
** Last update Sun May 24 22:24:23 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include "core.h"
#include "tools.h"
#include "const.h"

static t_key	g_keys[NB_KEYS] =
  {
    &backspace_hook,
    &enter_hook,
    &tabulation_hook,
    &control_d_hook,
    &control_l_hook,
    &catch_hook
  };

int	key_hook(t_core *core, const char *buffer)
{
  int	i;

  i = 0;
  while (i < NB_KEYS)
    {
      if (g_keys[i](core, buffer) == TRUE)
	return (TRUE);
      i++;
    }
  return (FALSE);
}
