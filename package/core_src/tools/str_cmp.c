/*
** str_cmp.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri May  1 15:01:18 2015 Guillaume ROBIN
** Last update Fri May  1 15:03:45 2015 Guillaume ROBIN
*/

#include <stdlib.h>
#include "tools.h"

int	str_cmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL && s2 != NULL)
    return (-1);
  else if (s1 != NULL && s2 == NULL)
    return (1);
  else if (s1 == NULL && s2 == NULL)
    return (0);
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (1);
      else if (s1[i] < s2[i])
	return (-1);
      i++;
    }
  if (s1[i] == '\0' && s2[i] != '\0')
    return (-1);
  else if (s1[i] != '\0' && s2[i] == '\0')
    return (1);
  return (0);
}
