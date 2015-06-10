/*
** buffer.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Apr 29 17:35:41 2015 Guillaume ROBIN
** Last update Sun May 24 13:50:05 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include "core.h"
#include "const.h"

void	clear_buffer_caps(char *buffer, int i)
{
  while (i < BUF_CAPS_SIZE)
    {
      buffer[i] = END_STR;
      i++;
    }
}

void	clear_buffer(char *buffer, int index)
{
  int	i;

  i = index;
  while (i <= BUFF_SIZE)
    {
      buffer[i] = END_STR;
      i++;
    }
}
