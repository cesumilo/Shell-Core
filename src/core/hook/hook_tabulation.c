/*
** hook_tabulation.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Apr 30 16:32:37 2015 Guillaume ROBIN
** Last update Sun May 24 14:25:13 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <glob.h>
#include "core.h"
#include "tools.h"
#include "const.h"

static int	get_last_slash(t_core *core)
{
  int		i;

  i = str_len(core->buf_caps) - 1;
  while (i > 0)
    {
      if (core->buf_caps[i] == ' ')
	return (i + 1);
      i--;
    }
  return (i == ERROR ? 0 : i);
}

static void	aff_list(t_core *core, const int ac, char **av)
{
  int		i;

  i = 0;
  put_str(BACKSPACE_STR);
  while (i < ac)
    {
      put_str(av[i]);
      put_str(BACKSPACE_STR);
      i++;
    }
  put_str(PROMPT_1(core->prompt));
}

int		tabulation_hook(t_core *core, const char *buffer)
{
  glob_t	match;
  int		index;
  int		ret;
  char		*pattern;

  if (buffer[0] != TABULATION)
    return (FALSE);
  index = get_last_slash(core);
  if (!(pattern = str_cat(&(core->buf_caps[index]), STR_STAR, NO_FREE)))
    return (TRUE);
  ret = glob(pattern, GLOB_MARK, NULL, &match);
  if (ret == GLOB_ABORTED || ret == GLOB_NOSPACE)
    my_puterr(ERR_GLOB);
  else if (ret == GLOB_NOMATCH)
    return (TRUE);
  if (match.gl_pathc == 1)
    {
      core->buf_caps[index] = END_STR;
      core->buf_caps = str_cat(core->buf_caps, match.gl_pathv[0], FREE_LEFT);
    }
  else if (match.gl_pathc > 1)
    aff_list(core, match.gl_pathc, match.gl_pathv);
  globfree(&match);
  free(pattern);
  return (TRUE);
}
