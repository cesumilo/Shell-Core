/*
** prompt.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Sun May 24 00:12:17 2015 Guillaume ROBIN
** Last update Sun May 24 14:15:33 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "core.h"
#include "tools.h"
#include "const.h"
#include "env.h"

char	*get_prompt(t_core *core)
{
  char	*str;
  char	*user;
  char	*path;

  free(core->prompt);
  str = NULL;
  str = str_cat(str, COLOR_LBLUE, FREE_LEFT);
  if ((user = get_env(core->env, STR_USER)) != NULL)
    str = str_cat(str, user, FREE_BOTH);
  str = str_cat(str, COLOR_END, FREE_LEFT);
  str = str_cat(str, COLOR_PWD_1, FREE_LEFT);
  if ((path = get_env(core->env, STR_ENVPWD)) != NULL)
    str = str_cat(str, path, FREE_BOTH);
  str = str_cat(str, COLOR_PWD_2, FREE_LEFT);
  return (str);
}
