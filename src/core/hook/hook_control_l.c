/*
** hook_control_l.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Sun May 24 22:22:17 2015 Guillaume ROBIN
** Last update Sun May 24 22:27:05 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include "core.h"
#include "tools.h"
#include "const.h"

int	control_l_hook(t_core *core, const char *buffer)
{
  if (core && buffer[0] == CONTROL_L)
    {
      put_str(CLEAR_FCT);
      return (TRUE);
    }
  return (FALSE);
}
