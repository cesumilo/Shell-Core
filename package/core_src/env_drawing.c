/*
** env_drawing.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Apr 29 16:56:48 2015 Guillaume ROBIN
** Last update Sun May 24 14:03:42 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "tools.h"
#include "const.h"
#include "env.h"

void	env_draw(t_env *env)
{
  t_env	*tmp;

  tmp = env;
  while (tmp != NULL)
    {
      put_str(tmp->data);
      put_str(BACKSPACE_STR);
      tmp = tmp->next;
    }
}
