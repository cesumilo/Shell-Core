/*
** get_env.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Apr 29 17:59:47 2015 Guillaume ROBIN
** Last update Sun May 24 14:06:33 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include <string.h>
#include "env.h"
#include "tools.h"
#include "const.h"

char	*get_env(t_env *env, const char *name)
{
  t_env	*tmp;
  char	*value;
  int	size;

  tmp = env;
  size = str_len(name);
  while (tmp != NULL && strncmp(tmp->data, name, size) != EQUAL)
    tmp = tmp->next;
  if (tmp == NULL)
    return (NULL);
  if (size >= str_len(tmp->data))
    return (NULL);
  if ((value = str_dup(&((tmp->data)[size]))) == NULL)
    return (NULL);
  return (value);
}
