/*
** hook_control_d.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Sun May 24 13:37:35 2015 Guillaume ROBIN
** Last update Sun May 24 14:22:00 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include "core.h"
#include "tools.h"
#include "const.h"

int	control_d_hook(t_core *core, const char *buffer)
{
  if (buffer[0] == CONTROL_D)
    {
      put_str(BACKSPACE_STR);
      core->shutdown = TRUE;
      return (TRUE);
    }
  return (FALSE);
}
