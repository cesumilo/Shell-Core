/*
** module_double_close_chevron.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon May 11 22:10:53 2015 Guillaume ROBIN
** Last update Sun May 24 15:20:29 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include "core.h"
#include "const.h"
#include "tools.h"

int	double_close_chevron_operation(t_core *core, t_mod_pack *packet,
				       t_module *mods)
{
  if (packet->rd_write == ERROR && packet->av != NULL)
    {
      core->err_open = open_file(get_fd(packet, TOK_DCCHV),
				 packet->av[0], get_flags(TOK_DCCHV),
				 get_mode(TOK_DCCHV));
    }
  else if (packet->rd_write != ERROR)
    return (execute_cmd(core, packet, mods));
  else
    return (ERROR);
  return (NO_ERR);
}
