/*
** count_word.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Apr 30 17:54:00 2015 Guillaume ROBIN
** Last update Fri Jun  5 18:06:11 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include "core.h"
#include "const.h"

int	is_token(const char c, const char *tokens)
{
  int	i;

  i = 0;
  while (i < NB_TOKENS && c != tokens[i])
    i++;
  return (i == NB_TOKENS ? 0 : 1);
}

void	pass_word(const char *str, int *index, const char *tokens)
{
  if (str && str[*index] != CHAR_DQUOTE)
    {
      while (str[*index] != END_STR && str[*index] != CHAR_SPACE
	     && str[*index] != CHAR_TAB && !is_token(str[*index], tokens))
	*index += 1;
    }
  else if (str)
    {
      *index += 1;
      while (str[*index] != END_STR && str[*index] != CHAR_DQUOTE)
	*index += 1;
      if (str[*index] == CHAR_DQUOTE)
	*index += 1;
    }
}

void	pass_sep(const char *str, int *index)
{
  while (str && str[*index] != END_STR
	 && (str[*index] == CHAR_SPACE || str[*index] == CHAR_TAB))
    *index += 1;
}

void	pass_token(const char *str, int *index, const char *tokens)
{
  while (str && str[*index] != END_STR && is_token(str[*index], tokens))
    *index += 1;
}

int	count_word(const char *str, const char *tokens)
{
  int	count;
  int	i;
  int	save;

  count = 0;
  i = 0;
  if (str == NULL)
    return (0);
  pass_sep(str, &i);
  while (str[i] != END_STR)
    {
      save = i;
      pass_word(str, &i, tokens);
      if (save < i)
	count++;
      pass_sep(str, &i);
      save = i;
      pass_token(str, &i, tokens);
      if (save < i)
	count++;
      pass_sep(str, &i);
    }
  return (count);
}
