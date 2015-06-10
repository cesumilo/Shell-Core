/*
** init_termcaps.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Apr 29 18:09:55 2015 Guillaume ROBIN
** Last update Sun May 24 14:08:17 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <unistd.h>
#include <termios.h>
#include <term.h>
#include "core.h"
#include "tools.h"
#include "const.h"

int	init_term(t_core *core, const int ac, char **av)
{
  if (ac >= 1 && (str_cmp(av[1], OPT_TERMCAPS_1) == EQUAL
		  || str_cmp(av[1], OPT_TERMCAPS_2) == EQUAL))
    {
      if (tcgetattr(0, core->term) == ERROR)
	return (my_puterr(ERR_GTERMC));
      if ((core->name_term = get_env(core->env, STR_TERM)) == NULL)
	{
	  core->is_tcaps = FALSE;
	  return (my_puterr(WAR_NOTERM));
	}
    }
  else
    core->is_tcaps = FALSE;
  return (NO_ERR);
}
