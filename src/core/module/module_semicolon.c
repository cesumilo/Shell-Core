/*
** module_semicolon.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon May 11 19:31:31 2015 Guillaume ROBIN
** Last update Sun May 24 15:24:55 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <unistd.h>
#include "core.h"
#include "const.h"
#include "tools.h"

int	semicolon_operation(t_core *core, t_mod_pack *packet, t_module *mods)
{
  return (execute_cmd(core, packet, mods));
}
