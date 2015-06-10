/*
** env_convert.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Apr 29 16:40:12 2015 Guillaume ROBIN
** Last update Sun May 24 14:02:19 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "env.h"
#include "tools.h"
#include "const.h"

char	**env_convert(t_env *env)
{
  char	**env_tab;
  t_env	*tmp;
  int	size;
  int	i;

  if ((size = env_size(env)) == 0)
    {
      my_puterr(WAR_NO_ENV);
      return (NULL);
    }
  if ((env_tab = malloc(sizeof(*env_tab) * (size + 1))) == NULL)
    {
      my_puterr(ERR_MALLOC);
      return (NULL);
    }
  i = 0;
  tmp = env;
  while (i < size && tmp != NULL)
    {
      env_tab[i] = tmp->data;
      i++;
      tmp = tmp->next;
    }
  env_tab[i] = NULL;
  return (env_tab);
}
