/*
** my_puterr.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Apr 29 18:12:08 2015 Guillaume ROBIN
** Last update Wed May  6 16:47:01 2015 Guillaume ROBIN
*/

#include <unistd.h>
#include <stdlib.h>
#include "tools.h"
#include "const.h"

int	my_puterr(const char *err)
{
  if (err == NULL)
    return (ERROR);
  (void) write(2, err, str_len(err));
  return (ERROR);
}
