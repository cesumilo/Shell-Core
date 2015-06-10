/*
** raw_mode.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Apr 29 17:48:09 2015 Guillaume ROBIN
** Last update Sun May 24 14:20:23 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include "core.h"
#include "tools.h"
#include "const.h"

void	enable_row_mode(struct termios *term)
{
  term->c_lflag &= ~(ICANON | ECHO);
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  (void)tcsetattr(0, TCSANOW, term);
}

void	disable_row_mode(struct termios *term)
{
  term->c_lflag |= (ICANON | ECHO);
  (void)tcsetattr(0, 0, term);
}
