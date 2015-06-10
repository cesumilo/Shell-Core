/*
** btree.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri May  1 11:37:53 2015 Guillaume ROBIN
** Last update Sun May 24 14:26:15 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "btree.h"

t_btree		*btree_insert_right(t_btree *root, char **cmd)
{
  t_btree	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->cmd = cmd;
  new->right = NULL;
  new->left = NULL;
  if (root == NULL)
    return (new);
  root->right = new;
  return (root);
}

t_btree		*btree_insert_left(t_btree *root, char **cmd)
{
  t_btree	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->cmd = cmd;
  new->right = NULL;
  new->left = NULL;
  if (root == NULL)
    return (new);
  root->left = new;
  return (root);
}

void		btree_free(t_btree *root)
{
  if (root != NULL)
    {
      if (root->right != NULL)
	btree_free(root->right);
      if (root->left != NULL)
	btree_free(root->left);
      free(root->cmd);
      free(root);
    }
}
