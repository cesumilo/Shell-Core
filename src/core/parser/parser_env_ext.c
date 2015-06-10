/*
** parser_env_ext.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed May 13 18:29:20 2015 Guillaume ROBIN
** Last update Sun May 24 15:11:50 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "parser.h"
#include "const.h"
#include "tools.h"

void	put_env_var(char **new, char *var, int size, int *i)
{
  int	j;

  j = 0;
  while (j < size)
    {
      (*new)[*i] = var[j];
      j++;
      *i += 1;
    }
}

int	is_env_var_error(char *name, char *var, char *err)
{
  free(name);
  free(var);
  return (my_puterr(err));
}

int	is_tilde(t_env *env, char **str, int i)
{
  char	*var;

  if (str == NULL)
    return (ERROR);
  while ((*str)[i] != END_STR)
    {
      if ((*str)[i] == TILDE)
	{
	  if ((var = get_env(env, STR_HOME)) == NULL)
	    return (is_env_var_error(NULL, NULL, ERR_GETENV));
	  add_var_into_str(str, i + 1, i + 1, var);
	  if (*str == NULL)
	    return (is_env_var_error(NULL, var, ERR_MALLOC));
	  free(var);
	}
      i++;
    }
  return (NO_ERR);
}
