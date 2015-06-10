/*
** module_pack_1.c for Core-Shell in /home/robin_f/Programming/Epitech/S2/C/PSU_2014_42sh/src/core/module
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jun  9 19:42:02 2015 Guillaume ROBIN
** Last update Tue Jun  9 23:05:38 2015 Guillaume ROBIN
*/

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "package.h"
#include "const.h"
#include "tools.h"

void	pipe_management(t_mod_pack *packet)
{
  if (signal(SIGINT, SIG_DFL) == SIG_ERR)
    my_puterr(ERR_SIGNAL);
  if (packet->p_write == TRUE
      && (dup2(packet->pipe[PIPEWRITE], STDOUT) == ERROR
	  || close(packet->pipe[PIPEREAD]) == ERROR))
    my_puterr(ERR_DUP2);
  if (packet->p_read == TRUE
      && dup2(packet->fd_read, STDIN) == ERROR)
    my_puterr(ERR_DUP2);
  packet->err = ERR_SHUTDOWN;
}

void	pipe_management_parent(t_mod_pack *packet)
{
  if (tcsetpgrp(STDIN, getpid()) == ERROR)
    my_puterr(ERR_TCSETPGRP);
  if (packet->p_write == TRUE && close(packet->pipe[PIPEWRITE]) == ERROR)
    my_puterr(ERR_PIPE);
  if (packet->p_read == TRUE)
    packet->p_read = FALSE;
  if (packet->is_dchv == TRUE)
    packet->is_dchv = FALSE;
}

int	manage_return(t_mod_pack *pack)
{
  return (pack->err == ERR_SHUTDOWN ? ERR_SD_PIPE : pack->err);
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

void	redirection_management_close(t_mod_pack *packet)
{
  if (packet->rd_write != ERROR && close(packet->rd_write) != ERROR)
    packet->rd_write = ERROR;
  if (packet->rd_read != ERROR && close(packet->rd_read) != ERROR)
    packet->rd_read = ERROR;
}
