/*
** module_chevron_management_ext.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon May 18 11:59:37 2015 Guillaume ROBIN
** Last update Tue Jun  9 19:47:30 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "core.h"
#include "const.h"
#include "tools.h"

void	redirection_management_close(t_mod_pack *packet)
{
  if (packet->rd_write != ERROR && close(packet->rd_write) != ERROR)
    packet->rd_write = ERROR;
  if (packet->rd_read != ERROR && close(packet->rd_read) != ERROR)
    packet->rd_read = ERROR;
}
