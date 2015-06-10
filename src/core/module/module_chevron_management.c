/*
** module_chevron_management.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon May 11 21:20:27 2015 Guillaume ROBIN
** Last update Tue Jun  9 19:44:58 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "core.h"
#include "const.h"
#include "tools.h"

int	open_file(int *fd, char *file, int flags, mode_t mode)
{
  if (!fd || (*fd = open(file, flags, mode)) == ERROR)
    {
      my_puterr(ERR_STR);
      my_puterr(file);
      my_puterr(ERR_END_OPEN);
      return (ERROR);
    }
  return (NO_ERR);
}

int	get_flags(char *token)
{
  if (str_cmp(token, TOK_SCCHV) == EQUAL)
    return (O_WRONLY | O_CREAT | O_TRUNC);
  else if (str_cmp(token, TOK_DCCHV) == EQUAL)
    return (O_WRONLY | O_CREAT | O_APPEND);
  else
    return (O_RDONLY);
}

mode_t	get_mode(char *token)
{
  if (str_cmp(token, TOK_SCCHV) == EQUAL
      || str_cmp(token, TOK_DCCHV) == EQUAL)
    return (S_IRUSR | S_IWUSR);
  return (0);
}

int	*get_fd(t_mod_pack *packet, char *token)
{
  if (str_cmp(token, TOK_SCCHV) == EQUAL
      || str_cmp(token, TOK_DCCHV) == EQUAL)
    return (&(packet->rd_write));
  else if (str_cmp(token, TOK_SOCHV) == EQUAL)
    return (&(packet->rd_read));
  return (NULL);
}

void	redirection_management(t_mod_pack *packet)
{
  if (packet->rd_write != ERROR)
    {
      if (dup2(packet->rd_write, STDOUT) == ERROR)
	my_puterr(ERR_DUP2);
    }
  if (packet->rd_read != ERROR)
    {
      if (dup2(packet->rd_read, STDIN) == ERROR)
	my_puterr(ERR_DUP2);
    }
}
