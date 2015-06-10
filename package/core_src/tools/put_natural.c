/*
** put_natural.c for put_natural in /home/perouz_l/Usp/PSU_2014_42sh/src/tools
** 
** Made by Lucien Perouze
** Login   <perouz_l@epitech.net>
** 
** Started on  Thu May 21 17:38:20 2015 Lucien Perouze
** Last update Sun May 24 16:08:59 2015 Guillaume ROBIN
*/

#include <unistd.h>
#include "tools.h"
#include "const.h"

void	put_str_natural(const char *str)
{
  int	i;

  put_str("$> ");
  i = 0;
  while (str[i] != END_STR)
    {
      (void)usleep(200000);
      put_char(str[i]);
      ++i;
    }
}
