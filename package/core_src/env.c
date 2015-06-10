/*
** env.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Apr 29 16:25:30 2015 Guillaume ROBIN
** Last update Sun May 24 14:00:50 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "env.h"
#include "tools.h"
#include "const.h"

t_env	*env_insert(t_env *old, char *var)
{
  t_env	*new;
  t_env	*tmp;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->data = var;
  new->next = NULL;
  tmp = old;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if (tmp == NULL)
    return (new);
  tmp->next = new;
  return (old);
}

void		env_free(t_env *env)
{
  t_env		*tmp;

  if (env != NULL)
    {
      while (env != NULL)
	{
	  tmp = env->next;
	  free(env->data);
	  free(env);
	  env = tmp;
	}
    }
}

static void	*intern_error(t_env *env)
{
  env_free(env);
  put_error(ERR_MALLOC);
  return (NULL);
}

t_env		*env_load(void)
{
  extern char	**environ;
  t_env		*env;
  int		i;
  char		*str;

  env = NULL;
  i = 0;
  if (environ == NULL)
    return (NULL);
  while (environ[i] != NULL)
    {
      if ((str = str_dup(environ[i])) == NULL)
	return (intern_error(env));
      if ((env = env_insert(env, str)) == NULL)
	return (intern_error(env));
      i++;
    }
  return (env);
}

int	env_size(t_env *env)
{
  t_env	*tmp;
  int	i;

  i = 0;
  tmp = env;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}
