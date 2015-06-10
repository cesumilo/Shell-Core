/*
** module_simple_open_chevron.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core/module
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue May 12 12:37:46 2015 Guillaume ROBIN
** Last update Sun May 24 15:27:11 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include "core.h"
#include "const.h"
#include "tools.h"

int	simple_open_chevron_operation(t_core *core, t_mod_pack *packet,
				      t_module *mods)
{
  if (core != NULL && mods != NULL && packet->av != NULL)
    {
      core->err_open = open_file(get_fd(packet, TOK_SOCHV),
				 packet->av[0], get_flags(TOK_SOCHV),
				 get_mode(TOK_SOCHV));
    }
  else
    return (ERROR);
  return (NO_ERR);
}
