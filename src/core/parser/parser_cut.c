/*
** parser_cut.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Apr 30 17:29:54 2015 Guillaume ROBIN
** Last update Wed Jun 10 13:01:07 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "core.h"
#include "tools.h"
#include "parser.h"
#include "const.h"

static char	g_tokens[NB_TOKENS] =
  {
    '|',
    '>',
    '<',
    ';',
    '&'
  };

static char	*get_word(const char *str, int *i, int j)
{
  char		*word;
  int		size;

  j = *i;
  pass_word(str, &j, g_tokens);
  size = j - *i;
  if (str[*i] == CHAR_DQUOTE)
    {
      size -= 2;
      *i += 1;
    }
  if (size < 0 || (word = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  j = 0;
  while (j < size)
    {
      word[j] = str[*i];
      j++;
      *i += 1;
    }
  if (str[*i] == CHAR_DQUOTE)
    *i += 1;
  word[j] = END_STR;
  return (word);
}

static char	*get_token(const char *str, int *i)
{
  char		*token;
  int		j;
  int		size;

  j = *i;
  pass_token(str, &j, g_tokens);
  size = j - *i;
  if (size == 0)
    return (NULL);
  if ((token = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  j = 0;
  while (j < size)
    {
      token[j] = str[*i];
      j++;
      *i += 1;
    }
  token[j] = END_STR;
  return (token);
}

void	parser_cut(t_core *core, const char *buffer)
{
  int	size;
  char	**tab;
  int	j;
  int	i;

  size = count_word(buffer, g_tokens);
  if ((core->cut_tab = malloc(sizeof(*tab) * (size + 1))) == NULL)
    return ;
  j = 0;
  i = 0;
  if (size > 0)
    pass_sep(buffer, &i);
  while (j < size && buffer[i] != END_STR)
    {
      (core->cut_tab)[j] = get_word(buffer, &i, 0);
      j++;
      pass_sep(buffer, &i);
      if (j < size && is_token(buffer[i], g_tokens))
	{
	  core->cut_tab[j] = get_token(buffer, &i);
	  j++;
	  pass_sep(buffer, &i);
	}
    }
  core->cut_tab[j] = NULL;
}

void	cut_tab_free(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	{
	  free(tab[i]);
	  i++;
	}
      free(tab);
    }
}

int	cut_tab_size(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	i++;
    }
  return (i);
}
