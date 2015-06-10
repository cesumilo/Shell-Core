/*
** module_pack_4.c for package in /home/robin_f/Programming/Epitech/S2/C/PSU_2014_42sh/package
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jun  9 20:46:50 2015 Guillaume ROBIN
** Last update Tue Jun  9 23:06:05 2015 Guillaume ROBIN
*/

#include <stdlib.h>
#include "package.h"

void	cut_tab_free(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	{
	  free(tab[i]);
	  i++;
	}
      free(tab);
    }
}

int	cut_tab_size(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	i++;
    }
  return (i);
}
