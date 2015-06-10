/*
** get_next_line.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/tools
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri May 22 22:27:58 2015 Guillaume ROBIN
** Last update Fri May 22 22:27:58 2015 Guillaume ROBIN
*/

#include <unistd.h>
#include "get_next_line.h"

static void	clear_buffer(char *buffer, int *index, int *clear)
{
  int		i;

  i = 0;
  if (*clear == 1)
    {
      *index = 0;
      *clear = 0;
    }
  if (*index == 0)
    {
      while (i < ABS(READ_MAX))
	{
	  buffer[i] = '\0';
	  i = i + 1;
	}
    }
}

static int	check_buffer(char *buffer)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (buffer[i] == '\0' && i < ABS(READ_MAX))
    i = i + 1;
  if (i == ABS(READ_MAX))
    return (0);
  else
    {
      while (i < ABS(READ_MAX))
	{
	  buffer[j] = buffer[i];
	  buffer[i] = '\0';
	  j = j + 1;
	  i = i + 1;
	}
    }
  return (j);
}

static int	len(char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
	i = i + 1;
    }
  return (i);
}

static char	*new_str(char *b, char *str, int *ret, int i)
{
  char		*nstr;
  int		j;

  if ((nstr = malloc(len(str) + ABS(READ_MAX) + 1)) == NULL)
    return (NULL);
  j = 0;
  while (str != NULL && i < len(str) + ABS(READ_MAX) && str[i] != '\0')
    {
      nstr[i] = str[i];
      i = i + 1;
    }
  while (i < len(str) + ABS(READ_MAX) && j < ABS(READ_MAX) && b[j] != '\n')
    {
      nstr[i] = b[j];
      b[j] = '\0';
      i = i + 1;
      j = j + 1;
    }
  if (b[j] == '\n')
    *ret = 0;
  b[j] = '\0';
  nstr[i] = '\0';
  free(str);
  return (nstr);
}

char		*get_next_line(const int fd, int *clear)
{
  static char	buf[ABS(READ_MAX)];
  static int	index = 0;
  int		ret;
  int		stop;
  char		*str;

  if (*clear == 1)
    clear_buffer(buf, &index, clear);
  index = check_buffer(buf);
  clear_buffer(buf, &index, clear);
  str = NULL;
  stop = 1;
  ret = 1;
  while (ret > 0 && stop > 0)
    {
      ret = read(fd, &buf[index], ABS(READ_MAX) - index);
      str = new_str(buf, str, &stop, 0);
    }
  if (fd < 0 || ret < 0 || (ret == 0 && index == 0 && str != NULL
			    && str[0] == '\0'))
    {
      free(str);
      return (NULL);
    }
  return (str);
}
