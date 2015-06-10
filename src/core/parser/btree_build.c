/*
** btree_build.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri May  1 14:51:54 2015 Guillaume ROBIN
** Last update Sun May 24 14:27:30 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "btree.h"
#include "parser.h"
#include "tools.h"
#include "const.h"

/*
** La disposition des tokens n'est pas aléatoire ! (cf. parser.h)
*/

static char	*g_tokens[TOKENS] =
  {
    ">",
    ">>",
    "<",
    "<<",
    "|",
    ";",
    "&&",
    "||"
  };

static int	is_complete_token(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (i < TOKENS && str_cmp(str, g_tokens[i]) != 0)
    i++;
  return (i == TOKENS ? 0 : 1);
}

static int	is_redir_token(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (i < TOK_REDIR && str_cmp(str, g_tokens[i]) != 0)
    i++;
  return (i == TOK_REDIR ? 0 : 1);
}

static void	get_token(char **cut_tab, int *i, int size)
{
  while (*i < size && is_complete_token(cut_tab[*i]) != 1)
    *i += 1;
}

static t_btree	**move_foreward(t_btree **tmp, char **buffer)
{
  static int	next_move = FALSE;

  if (buffer != NULL && next_move == FALSE)
    next_move = TRUE;
  else if (next_move == TRUE && *tmp != NULL && (*tmp)->right != NULL)
    {
      tmp = &((*tmp)->right->right);
      next_move = FALSE;
    }
  else if (*tmp != NULL && buffer == NULL)
    tmp = &((*tmp)->right);
  return (tmp);
}

void		btree_build(char **cut_tab, t_btree **root)
{
  static char	**buffer = NULL;
  int		i;
  int		j;
  int		size;
  t_data	data;
  t_btree	**tmp;
  char		is_rev;

  tmp = root;
  is_rev = FALSE;
  i = 0;
  size = cut_tab_size(cut_tab);
  while (i < size)
    {
      j = i;
      get_token(cut_tab, &i, size);
      data.tab = &(cut_tab[j]);
      data.root = *tmp;
      if (i > j)
	*tmp = insert_normal_token(&data, i - j + 1, &buffer, &is_rev);
      else if (is_redir_token(cut_tab[i]) == 1)
	*tmp = insert_rev_token(*tmp, cut_tab, &i, &is_rev);
      tmp = move_foreward(tmp, buffer);
      i++;
    }
}
