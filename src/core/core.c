/*
** core.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri May 22 22:23:46 2015 Guillaume ROBIN
** Last update Tue Jun  9 22:16:49 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include <signal.h>
#include "core.h"
#include "tools.h"
#include "const.h"
#include "parser.h"

static void	core_free(t_core *core)
{
  free(core->name_term);
  cut_tab_free(core->cut_tab);
  env_free(core->env);
  jobs_free(core->jobs);
  close_modules(core->mods);
}

static void	init_core(t_core *core, struct termios *term)
{
  core->shutdown = 0;
  core->term = term;
  core->is_tcaps = TRUE;
  core->cut_tab = NULL;
  core->packet = NULL;
  core->name_term = NULL;
  core->jump = FALSE;
  core->err_open = NO_ERR;
  core->buf_caps = NULL;
  core->jobs = NULL;
  core->prompt = NULL;
  core->mods = get_modules();
  if (signal(SIGINT, SIG_IGN) == SIG_ERR)
    my_puterr(ERR_SIGNAL);
  if (signal(SIGTTOU, SIG_IGN) == SIG_ERR)
    my_puterr(ERR_SIGNAL);
}

int			main(int ac, char **av)
{
  t_core		core;
  struct termios	term;
  int			ret;

  init_core(&core, &term);
  if ((core.env = env_load()) == NULL)
    my_puterr(ERR_ENV);
  core.prompt = get_prompt(&core);
  init_term(&core, ac, av);
  core_config_file(&core);
  if (core.is_tcaps)
    enable_row_mode(core.term);
  if (core.is_tcaps && !(ret = core_run_termcap(&core)))
    return (ret);
  if (!core.is_tcaps && !(ret = core_run_no_termcap(&core)))
    return (ret);
  if (core.shutdown != ERR_SD_PIPE && core.is_tcaps)
    disable_row_mode(core.term);
  core_free(&core);
  return (core.shutdown == 1 ? 0 : core.shutdown);
}
