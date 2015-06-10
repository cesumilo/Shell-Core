/*
** env_ext.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon May 11 15:09:30 2015 Guillaume ROBIN
** Last update Sun May 24 14:05:04 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include <string.h>
#include "env.h"
#include "tools.h"
#include "const.h"

t_env	*unset_env(t_env *env, char *name)
{
  t_env	*tmp;
  t_env	*prev;

  tmp = env;
  prev = NULL;
  while (tmp != NULL && tmp->data != NULL
	 && strncmp(name, tmp->data, str_len(name)) != 0)
    {
      prev = tmp;
      tmp = tmp->next;
    }
  if (tmp == NULL)
    return (env);
  if (prev == NULL)
    env = tmp->next;
  else
    {
      prev->next = tmp->next;
      free(tmp->data);
      free(tmp);
    }
  return (env);
}

t_env	*set_env(t_env *env, char *name, char *var)
{
  char	*new_name;
  char	*new;

  env = unset_env(env, name);
  new_name = str_cat(name, STR_EQUAL, NO_FREE);
  new = str_cat(new_name, var, NO_FREE);
  free(new_name);
  env = env_insert(env, new);
  return (env);
}
