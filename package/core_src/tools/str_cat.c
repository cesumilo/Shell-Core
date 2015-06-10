/*
** str_cat.c for str_cat in /home/perouz_l/Usp/PSU_2014_42sh/src/tools
** 
** Made by Lucien Perouze
** Login   <perouz_l@epitech.net>
** 
** Started on  Mon May  4 16:12:41 2015 Lucien Perouze
** Last update Sat May 23 12:04:34 2015 Guillaume ROBIN
*/

#include <stdlib.h>
#include "tools.h"

static void	free_params(char *str1, char *str2, const char opt)
{
  if (opt == 0 && str1)
    free(str1);
  else if (opt == 1 && str2)
    free(str2);
  else if (opt == 2 && str1 && str2)
    {
      free(str1);
      free(str2);
    }
  str1 = NULL;
  str2 = NULL;
}

char	*str_cat(char *str1, char *str2, const char opt)
{
  char	*end;
  int	i;
  int	u;

  if (!(end = malloc(str_len(str1) + str_len(str2) + 1)))
    return (NULL);
  i = 0;
  while (str1 != NULL && str1[i] != '\0')
    {
      end[i] = str1[i];
      i++;
    }
  u = 0;
  while (str2 != NULL && str2[u] != '\0')
    {
      end[i] = str2[u];
      i++;
      u++;
    }
  end[i] = '\0';
  free_params(str1, str2, opt);
  return (end);
}
