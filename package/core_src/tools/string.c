/*
** string.c for string in /home/perouz_l/Usp/PSU_2014_42sh/tools
** 
** Made by Lucien Perouze
** Login   <perouz_l@epitech.net>
** 
** Started on  Wed Apr 29 16:31:24 2015 Lucien Perouze
** Last update Sat May 23 21:24:59 2015 Guillaume ROBIN
*/

#include <unistd.h>
#include "tools.h"
#include "const.h"

int	str_len(const char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != END_STR)
	i++;
    }
  return (i);
}

void	put_char(const char c)
{
  (void) write(1, &c, 1);
}

void	put_str(const char *str)
{
  (void) write(1, str, str_len(str));
}

void	put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = nb * -1;
      put_char('-');
    }
  if (nb && nb / 10)
    put_nbr(nb / 10);
  put_char(nb % 10 + '0');
}
