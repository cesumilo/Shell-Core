/*
** hook_catch.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu May 21 11:40:08 2015 Guillaume ROBIN
** Last update Sun May 24 14:21:40 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include "core.h"
#include "const.h"

int	catch_hook(t_core *core, const char *buffer)
{
  if (core != NULL && buffer[0] == ESCAPE)
    return (TRUE);
  return (FALSE);
}
