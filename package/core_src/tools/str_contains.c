/*
** str_contains.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed May 13 16:19:42 2015 Guillaume ROBIN
** Last update Wed May 13 16:30:35 2015 Guillaume ROBIN
*/

#include <stdlib.h>
#include "tools.h"
#include "const.h"

int	char_in_str(const char *str, const char c)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (FALSE);
  while (str[i] != END_STR)
    {
      if (str[i] == c)
	return (TRUE);
      i++;
    }
  return (FALSE);
}
