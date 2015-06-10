/*
** hook_enter.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Apr 30 11:38:39 2015 Guillaume ROBIN
** Last update Sun May 24 14:22:42 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include "core.h"
#include "tools.h"
#include "const.h"
#include "parser.h"

int	enter_hook(t_core *core, const char *buffer)
{
  if (buffer[0] == ENTER)
    {
      put_str(BACKSPACE_STR);
      disable_row_mode(core->term);
      parser(core, core->buf_caps);
      enable_row_mode(core->term);
      core->prompt = get_prompt(core);
      if (!core->shutdown)
	put_str(PROMPT_1(core->prompt));
      free(core->buf_caps);
      core->buf_caps = str_dup("");
      return (TRUE);
    }
  return (FALSE);
}
