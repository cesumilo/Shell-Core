/*
** parser.h for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri May  1 11:35:38 2015 Guillaume ROBIN
** Last update Mon May 18 16:30:06 2015 Guillaume ROBIN
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "env.h"
# include "btree.h"

# define TOKENS		8
# define TOK_REDIR	4

typedef struct	s_data
{
  char		**tab;
  t_btree	*root;
}		t_data;

void		cut_tab_free(char **);
int		cut_tab_size(char **);
int		is_redir(char *str);
char		**create_subtab(char **cut_tab, int begin, int end);
void		put_env_var(char **new, char *var, int size, int *i);
int		is_env_var_error(char *name, char *var, char *err);
int		is_tilde(t_env *env, char **str, int i);
void		add_var_into_str(char **str, int begin, int end, char *var);
t_btree		*insert_normal_token(t_data *data, int size,
				     char ***buffer, char *is_rev);
t_btree		*insert_rev_token(t_btree *root, char **cut_tab,
				  int *i, char *is_rev);

#endif /* !PARSER_H_ */
