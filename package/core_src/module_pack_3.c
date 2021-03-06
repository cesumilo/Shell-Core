/*
** module_pack_3.c for Shell-Core in /home/robin_f/Programming/Epitech/S2/C/PSU_2014_42sh/src/core/module
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jun  9 19:46:50 2015 Guillaume ROBIN
** Last update Tue Jun  9 23:05:55 2015 Guillaume ROBIN
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include "package.h"
#include "tools.h"
#include "const.h"

t_jobs		*jobs_insert(t_jobs *old, int pid, char **av)
{
  static int	_id = 0;
  t_jobs	*new;
  int		i;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (old);
  new->id = _id;
  _id++;
  new->pid = pid;
  new->next = old;
  i = 0;
  if (av != NULL)
    {
      new->cmd = NULL;
      while (av[i] != NULL)
	{
	  new->cmd = str_cat(new->cmd, SPACE_STR, FREE_LEFT);
	  new->cmd = str_cat(new->cmd, av[i], FREE_LEFT);
	  i++;
	}
    }
  return (new);
}

t_jobs		*jobs_remove(t_jobs *list, int id)
{
  t_jobs	*tmp;
  t_jobs	*prev;

  tmp = list;
  prev = NULL;
  while (tmp != NULL && tmp->id != id)
    {
      prev = tmp;
      tmp = tmp->next;
    }
  if (tmp == NULL)
    return (list);
  if (prev == NULL)
    list = list->next;
  else
    prev->next = tmp->next;
  free(tmp->cmd);
  free(tmp);
  return (list);
}

int		jobs_get_pid(t_jobs *list, int id)
{
  t_jobs	*tmp;

  tmp = list;
  while (tmp != NULL && tmp->id != id)
    tmp = tmp->next;
  return (tmp != NULL ? tmp->pid : ERROR);
}

void		jobs_free(t_jobs *list)
{
  t_jobs	*tmp;

  if (list != NULL)
    {
      while (list != NULL)
	{
	  tmp = list->next;
	  if (kill(list->pid, SIGINT) == ERROR)
	    my_puterr(ERR_KILL);
	  free(list->cmd);
	  free(list);
	  list = tmp;
	}
    }
}
