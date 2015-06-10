/*
** create_subtab.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed May  6 17:28:45 2015 Guillaume ROBIN
** Last update Sun May 24 14:36:14 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "parser.h"
#include "tools.h"

char	**create_subtab(char **cut_tab, int begin, int end)
{
  char	**tab;
  int	size;
  int	i;

  size = end - begin;
  if ((tab = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  tab[size] = NULL;
  i = 0;
  while (i < size)
    {
      tab[i] = cut_tab[begin];
      i++;
      begin++;
    }
  return (tab);
}
