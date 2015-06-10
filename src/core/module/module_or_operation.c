/*
** module_or_operation.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu May 21 08:42:41 2015 Guillaume ROBIN
** Last update Sun May 24 15:23:41 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include "core.h"
#include "const.h"

int	or_operation(t_core *core, t_mod_pack *packet, t_module *mods)
{
  if (packet->av == NULL)
    return (ERROR);
  return (execute_cmd(core, packet, mods));
}
