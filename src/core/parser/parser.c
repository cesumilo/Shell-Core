/*
** parser.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Apr 30 16:55:38 2015 Guillaume ROBIN
** Last update Sun May 24 14:40:13 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "core.h"
#include "tools.h"
#include "const.h"
#include "parser.h"
#include "btree.h"

void		parser(t_core *core, const char *buffer)
{
  t_btree	*root;

  parser_cut(core, buffer);
  parser_env(cut_tab_size(core->cut_tab), core->cut_tab, core->env);
  root = NULL;
  if (core->cut_tab == NULL)
    {
      put_error(ERR_MALLOC);
      core->shutdown = 1;
    }
  else
    {
      btree_build(core->cut_tab, &root);
      module_call(core, root);
      btree_free(root);
      cut_tab_free(core->cut_tab);
      core->cut_tab = NULL;
    }
}
