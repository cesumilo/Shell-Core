/*
** str_dup.c for str_dup in /home/perouz_l/Usp/PSU_2014_42sh/tools
** 
** Made by Lucien Perouze
** Login   <perouz_l@epitech.net>
** 
** Started on  Wed Apr 29 16:38:47 2015 Lucien Perouze
** Last update Thu May 21 15:57:54 2015 Guillaume ROBIN
*/

#include <stdlib.h>
#include "tools.h"
#include "const.h"

char	*str_dup(const char *old)
{
  char	*new;
  int	i;

  if ((new = malloc(str_len(old) + 1)) == NULL)
    {
      put_error(ERR_MALLOC);
      return (NULL);
    }
  i = 0;
  while (old[i] != '\0')
    {
      new[i] = old[i];
      i++;
    }
  if (new != NULL)
    new[i] = '\0';
  return (new);
}
