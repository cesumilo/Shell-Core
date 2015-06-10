/*
** insert_token_dir.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon May 18 09:54:09 2015 Guillaume ROBIN
** Last update Sun May 24 14:36:41 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "btree.h"
#include "parser.h"
#include "tools.h"
#include "const.h"

int	is_redir(char *str)
{
  if (str_cmp(str, TOK_SCCHV) == EQUAL || str_cmp(str, TOK_DCCHV) == EQUAL
      || str_cmp(str, TOK_SOCHV) == EQUAL || str_cmp(str, TOK_DOCHV) == EQUAL)
    return (TRUE);
  return (FALSE);
}
