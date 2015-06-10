/*
** module_and_operation.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue May 19 08:47:03 2015 Guillaume ROBIN
** Last update Sun May 24 15:12:20 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include "core.h"
#include "const.h"

int	and_operation(t_core *core, t_mod_pack *packet, t_module *mods)
{
  if (packet->av == NULL)
    return (ERROR);
  return (execute_cmd(core, packet, mods));
}
