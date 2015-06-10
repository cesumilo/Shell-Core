/*
** btree_insert_cmd.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed May  6 17:32:15 2015 Guillaume ROBIN
** Last update Sun May 24 14:30:21 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "btree.h"
#include "parser.h"
#include "const.h"

static void	*intern_error(char **cmd, char **tok)
{
  free(cmd);
  free(tok);
  return (NULL);
}

static t_btree	*insert_buf(t_btree *root, char **tab, char ***buf, int size)
{

  if (*buf != NULL && tab[size - 1] != NULL && root != NULL
      && (root->right = btree_insert_left(root->right, *buf)) == NULL)
    return (NULL);
  else if (*buf != NULL && tab[size - 1] == NULL && root != NULL
	   && (root->right = btree_insert_right(root->right, *buf)) == NULL)
    return (NULL);
  *buf = NULL;
  return (root);
}

static t_btree	*insert_cmd(t_btree *root, char *tab, char ***buf, char **cmd)
{
  if (*buf != NULL && tab == NULL
      && (root = btree_insert_left(root, cmd)) == NULL)
    return (NULL);
  else if (*buf == NULL && tab == NULL
	   && (root = btree_insert_right(root, cmd)) == NULL)
    return (NULL);
  else if (tab != NULL && (root = btree_insert_left(root, cmd)) == NULL)
    return (NULL);
  return (root);
}

t_btree		*insert_normal_token(t_data *data, int size, char ***buf,
				     char *is_rev)
{
  char		**cmd;
  char		**tok;

  tok = NULL;
  if ((cmd = create_subtab(data->tab, 0, size - 1)) == NULL)
    return (data->root);
  if (data->tab[size - 1] != NULL
      && ((tok = create_subtab(data->tab, size - 1, size)) == NULL
	  || (data->root = btree_insert_right(data->root, tok)) == NULL))
    return (intern_error(cmd, tok));
  if (*is_rev == FALSE && *buf == NULL && is_redir(data->tab[size - 1]) == TRUE)
    *buf = cmd;
  else
    {
      if ((data->root = insert_cmd(data->root, data->tab[size - 1], buf, cmd))
	  == NULL)
	return (intern_error(cmd, tok));
      if ((data->root = insert_buf(data->root, data->tab, buf, size)) == NULL)
	return (intern_error(cmd, tok));
      *is_rev = FALSE;
    }
  return (data->root);
}

t_btree		*insert_rev_token(t_btree *root, char **cut_tab, int *i,
				  char *is_rev)
{
  char		**tok;
  char		**cmd;

  cmd = NULL;
  tok = NULL;
  if ((tok = create_subtab(cut_tab, *i, *i + 1)) == NULL)
    return (root);
  if (cut_tab[*i + 1] != NULL)
    {
      if ((cmd = create_subtab(cut_tab, *i + 1, *i + 2)) == NULL)
	{
	  free(tok);
	  return (root);
	}
    }
  if ((root = btree_insert_right(root, tok)) == NULL)
    return (intern_error(cmd, tok));
  if ((root = btree_insert_left(root, cmd)) == NULL)
    return (intern_error(cmd, tok));
  *is_rev = TRUE;
  *i += 1;
  return (root);
}
