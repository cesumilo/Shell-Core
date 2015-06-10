/*
** module_pack_2.c for Shell-Core in /home/robin_f/Programming/Epitech/S2/C/PSU_2014_42sh/src/core/module
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jun  9 19:45:18 2015 Guillaume ROBIN
** Last update Tue Jun  9 23:05:48 2015 Guillaume ROBIN
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "package.h"
#include "const.h"
#include "tools.h"

void	signal_handler(void)
{
  if (setpgid(0, 0) == ERROR)
    my_puterr(WAR_SETSID);
}

void	signal_handler_parent(int child)
{
  if (tcsetpgrp(STDIN, child) == ERROR)
    my_puterr(ERR_TCSETPGRP);
}

static int	check_error(int pid, int status, t_mod_pack *packet)
{
  if (WIFEXITED(status) && WEXITSTATUS(status) != NO_ERR_0)
    return (ERROR);
  else if (WIFSTOPPED(status))
    {
      *(packet->jobs) = jobs_insert(*(packet->jobs), pid, packet->av);
      printf(INFO_JOBS, (*(packet->jobs))->id, (*(packet->jobs))->cmd);
    }
  return (NO_ERR);
}

int	check_signal(int pid, int status, t_mod_pack *packet)
{
  if (WIFSIGNALED(status) && WTERMSIG(status) == SIGHUP)
    return (my_puterr(ERR_SIGHUP));
  else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
    return (my_puterr(ERR_SIGINT));
  else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
    return (my_puterr(ERR_SIGQUIT));
  else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGILL)
    return (my_puterr(ERR_SIGILL));
  else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGFPE)
    return (my_puterr(ERR_SIGFPE));
  else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGKILL)
    return (my_puterr(ERR_SIGKILL));
  else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
    return (my_puterr(ERR_SIGSEGV));
  else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGPIPE)
    return (my_puterr(ERR_SIGPIPE));
  else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGTERM)
    return (my_puterr(ERR_SIGTERM));
  else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSTOP)
    return (my_puterr(ERR_SIGSTOP));
  else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGTSTP)
    return (my_puterr(ERR_SIGTSTP));
  return (check_error(pid, status, packet));
}
