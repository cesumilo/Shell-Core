/*
** btree.h for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed May  6 17:17:11 2015 Guillaume ROBIN
** Last update Mon May 18 16:29:28 2015 Guillaume ROBIN
*/

#ifndef BTREE_H_
# define BTREE_H_

typedef struct		s_btree
{
  char			**cmd;
  struct s_btree	*right;
  struct s_btree	*left;
}			t_btree;

t_btree			*btree_insert_right(t_btree *root, char **cmd);
t_btree			*btree_insert_left(t_btree *root, char **cmd);
void			btree_free(t_btree *root);
void			btree_build(char **cut_tab, t_btree **root);

#endif /* !BTREE_H_ */
