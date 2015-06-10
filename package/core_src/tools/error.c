/*
** error.c for error in /home/perouz_l/Usp/PSU_2014_42sh/tools
** 
** Made by Lucien Perouze
** Login   <perouz_l@epitech.net>
** 
** Started on  Wed Apr 29 16:19:28 2015 Lucien Perouze
** Last update Sun May 24 16:07:51 2015 Guillaume ROBIN
*/

#include <unistd.h>
#include "tools.h"
#include "const.h"

static void	put_str_error(const char *str)
{
  (void) write(2, str, str_len(str));
}

static void	put_id_error(int id)
{
  char		digit;

  if (id && id / 10)
    put_id_error(id);
  digit = id % 10 + '0';
  (void) write(2, &digit, 1);
}

int		put_error(const char *message)
{
  static int	id = 0;

  if (!id)
    {
      put_str_error("\n+---------------------------------------+\n");
      put_str_error("|                                       |\n");
      put_str_error("|            ERROR DETECTED             |\n");
      put_str_error("|                                       |\n");
      put_str_error("+---------------------------------------+\n\n");
    }
  id++;
  put_id_error(id);
  put_str_error(". ");
  put_str_error(message);
  return (ERROR);
}
