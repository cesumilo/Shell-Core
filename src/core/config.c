/*
** module_config.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed May 20 15:10:05 2015 Guillaume ROBIN
** Last update Wed Jun 10 12:31:18 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "core.h"
#include "const.h"
#include "tools.h"
#include "get_next_line.h"

static int	is_commentary(const char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (TRUE);
  while (str[i] != END_STR && (str[i] == CHAR_SPACE || str[i] == CHAR_TAB)
	 && str[i] != CHAR_SHARP)
    i++;
  return (str[i] != CHAR_SHARP ? FALSE : TRUE);
}

void	core_config_file(t_core *core)
{
  int	fd;
  int	clear;

  clear = 0;
  if ((fd = open(CONFIG_PATH, O_RDONLY)) != ERROR)
    {
      while ((core->buffer_config = get_next_line(fd, &clear)) != NULL)
	{
	  if (is_commentary(core->buffer_config) == FALSE)
	    parser(core, core->buffer_config);
	  free(core->buffer_config);
	  core->buffer_config = NULL;
	}
      if (close(fd) == ERROR)
	my_puterr(ERR_CLOSE);
    }
}
