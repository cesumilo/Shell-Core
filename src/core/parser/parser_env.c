/*
** parser_env.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed May 13 15:58:03 2015 Guillaume ROBIN
** Last update Sun May 24 14:48:33 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "core.h"
#include "tools.h"
#include "const.h"
#include "parser.h"

static void	get_begin(char **new, char *str, int size, int *i)
{
  *i = 0;
  while (*i < size)
    {
      (*new)[*i] = str[*i];
      *i += 1;
    }
}

void	add_var_into_str(char **str, int begin, int end, char *var)
{
  char	*new;
  int	size;
  int	var_size;
  int	i;

  var_size = str_len(var);
  size = (str_len(*str) - (end - (begin - 1))) + var_size;
  if ((new = malloc(sizeof(char) * (size + 1))) != NULL)
    {
      get_begin(&new, *str, begin - 1, &i);
      put_env_var(&new, var, var_size, &i);
      while (i < size)
	{
	  new[i] = (*str)[end];
	  i++;
	  end++;
	}
      new[i] = END_STR;
      free(*str);
      *str = new;
    }
}

static char	*get_var_name(char *str, int begin, int *end)
{
  char		*name;
  int		i;
  int		size;

  i = begin;
  while (str[i] != END_STR
	 && (char_in_str(ENV_VARIABLE_1, str[i]) == TRUE
	     || char_in_str(ENV_VARIABLE_2, str[i]) == TRUE
	     || char_in_str(ENV_VARIABLE_3, str[i]) == TRUE))
    i++;
  if (i == begin)
    return (NULL);
  *end = i;
  size = i - begin;
  if ((name = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    {
      name[i] = str[begin];
      begin++;
      i++;
    }
  name[i] = END_STR;
  return (name);
}

static int	is_env_var(t_env *env, char **str, int i)
{
  int		end;
  char		*name;
  char		*var;

  if (str == NULL)
    return (ERROR);
  while ((*str)[i] != END_STR)
    {
      if ((*str)[i] == VAR_STR)
	{
	  if ((name = get_var_name(*str, i + 1, &end)) == NULL
	      || (name != NULL
		  && !(name = str_cat(name, STR_EQUAL, FREE_LEFT))))
	    return (is_env_var_error(name, NULL, ERR_MALLOC));
	  if ((var = get_env(env, name)) == NULL)
	    return (is_env_var_error(name, var, NULL));
	  add_var_into_str(str, i + 1, end, var);
	  if (*str == NULL)
	    return (is_env_var_error(name, var, ERR_MALLOC));
	  free(var);
	  free(name);
	}
      i++;
    }
  return (NO_ERR);
}

void	parser_env(const int ac, char **av, t_env *env)
{
  int	i;

  i = 0;
  if (av != NULL)
    {
      while (i < ac)
	{
	  is_env_var(env, &(av[i]), 0);
	  is_tilde(env, &(av[i]), 0);
	  i++;
	}
    }
}
