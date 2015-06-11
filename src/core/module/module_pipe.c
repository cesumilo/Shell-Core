/*
** module_pipe.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri May  8 16:16:17 2015 Guillaume ROBIN
** Last update Thu Jun 11 16:03:04 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <unistd.h>
#include <signal.h>
#include "core.h"
#include "const.h"
#include "tools.h"

int	pipe_operation(t_core *core, t_mod_pack *packet, t_module *mods)
{
  if (packet->av == NULL)
    return (ERROR);
  if (pipe(packet->pipe) == ERROR)
    {
      packet->p_read = FALSE;
      packet->p_write = FALSE;
      my_puterr(ERR_PIPE);
      return (ERROR);
    }
  else
    packet->p_write = TRUE;
  return (execute_cmd(core, packet, mods));
}

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
  if (pack->err == ERROR)
    return (ERR_SD_PIPE);
  return (pack->err == ERR_SHUTDOWN ? ERR_SD_PIPE : pack->err);
}
