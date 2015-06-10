/*
** put_str_fd.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core/module
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue May 12 13:40:08 2015 Guillaume ROBIN
** Last update Tue May 12 13:55:26 2015 Guillaume ROBIN
*/

#include <unistd.h>
#include "tools.h"

int	put_str_fd(const int fd, const char *str)
{
  return (write(fd, str, str_len(str)));
}
