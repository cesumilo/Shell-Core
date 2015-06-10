/*
** module_call_ext.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon May 11 19:52:21 2015 Guillaume ROBIN
** Last update Tue Jun  9 18:19:44 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "core.h"
#include "parser.h"
#include "const.h"
#include "tools.h"

static int	manage_and(t_core *core, int ret, t_btree **tmp)
{
  if (*tmp != NULL && (*tmp)->cmd != NULL
      && str_cmp(TOK_AND, (*tmp)->cmd[0]) == EQUAL
      && (ret == ERROR || core->err_open == ERROR))
    {
      while (*tmp != NULL && (*tmp)->cmd != NULL
	     && str_cmp((*tmp)->cmd[0], TOK_SEMICOLON) != EQUAL)
	*tmp = (*tmp)->right;
      return (NO_ERR);
    }
  return (ERROR);
}

static int	manage_or(t_core *core, int ret, t_btree **tmp)
{
  if (*tmp != NULL && (*tmp)->cmd != NULL
      && str_cmp(TOK_OR, (*tmp)->cmd[0]) == EQUAL)
    {
      if ((*tmp)->right != NULL && (*tmp)->right->cmd != NULL
	  && is_redir((*tmp)->right->cmd[0]))
	{
	  if (ret == ERROR)
	    *tmp = (*tmp)->right;
	  else if ((*tmp)->right != NULL && (*tmp)->right->right != NULL)
	    *tmp = (*tmp)->right->right->right;
	}
      else
	{
	  if (ret == ERROR || core->err_open == ERROR)
	    *tmp = (*tmp)->right;
	  else if ((*tmp)->right != NULL)
	    *tmp = (*tmp)->right->right;
	  else if (*tmp != NULL)
	    *tmp = (*tmp)->right;
	}
      return (NO_ERR);
    }
  return (ERROR);
}

t_btree	*manage_module_call(t_core *core, int ret, t_btree *tmp)
{
  if (ret == ERROR)
    return (NULL);
  if (manage_and(core, ret, &tmp) != ERROR)
    return (tmp);
  if (manage_or(core, ret, &tmp) != ERROR)
    return (tmp);
  else if (core->jump == TRUE && tmp != NULL && tmp->right != NULL)
    {
      tmp = tmp->right->right;
      core->jump = FALSE;
    }
  else if (tmp != NULL)
    tmp = tmp->right;
  return (tmp);
}
