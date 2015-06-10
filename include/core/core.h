/*
** core.h for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Apr 29 16:20:04 2015 Guillaume ROBIN
** Last update Tue Jun  9 21:18:59 2015 Guillaume ROBIN
*/

#ifndef CORE_H_
# define CORE_H_

# include <unistd.h>
# include <termios.h>
# include <sys/types.h>

# include "env.h"
# include "keys.h"
# include "module.h"
# include "btree.h"

# define BUFF_SIZE	4096
# define PROMPT_2	"> "
# define NB_TOKENS	5

# define PROMPT_1(x)(x == NULL ? "$> " : x)

typedef struct		s_core
{
  char			*name_term;
  char			*prompt;
  struct termios	*term;
  t_env			*env;
  char			*buf_caps;
  char			buffer[BUFF_SIZE + 1];
  char			*buffer_config;
  char			is_tcaps;
  int			shutdown;
  char			**cut_tab;
  t_mod_pack		*packet;
  char			jump;
  char			err_open;
  t_jobs		*jobs;
  t_module		*mods;
}			t_core;

typedef struct	s_op_token
{
  char		*token;
  int		(*op)(t_core *core, t_mod_pack *packet, t_module *modules);
}		t_op_tok;

typedef int	(*t_key)(t_core *core, const char *buffer);

/*
** Core's methods.
*/
int		core_run_termcap(t_core *core);
int		core_run_no_termcap(t_core *core);
void		core_config_file(t_core *core);

/*
** Swag method.
*/
char		*get_prompt(t_core *core);

/*
** Buffer management.
*/
void		clear_buffer(char *buffer, int i);
void		clear_buffer_caps(char *buffer, int i);
int		key_hook(t_core *core, const char *buffer);

/*
** Termcaps methods.
*/
int		out_c(int c);
int		init_term(t_core *core, const int ac, char **av);
void		enable_row_mode(struct termios *term);
void		disable_row_mode(struct termios *term);
int		reset_cursor(t_core *core, int pos);
int		move_cursor_left(t_core *core);

/*
** Keys hook.
*/
int		backspace_hook(t_core *core, const char *buffer);
int		enter_hook(t_core *core, const char *buffer);
void		escape_hook(t_core *core, int *index);
int		tabulation_hook(t_core *core, const char *buffer);
int		control_d_hook(t_core *core, const char *buffer);
int		control_l_hook(t_core *core, const char *buffer);
int		catch_hook(t_core *core, const char *buffer);

/*
** Parser methods
*/
void		parser(t_core *core, const char *buffer);
void		parser_cut(t_core *core, const char *buffer);
void		parser_env(const int ac, char **av, t_env *env);
int		is_token(const char c, const char *tokens);
void		pass_sep(const char *str, int *index);
void		pass_word(const char *str, int *index, const char *tokens);
void		pass_token(const char *str, int *index, const char *tokens);
int		count_word(const char *str, const char *tokens);

/*
** Module calling.
*/
int		open_file(int *fd, char *file, int flags, mode_t mode);
int		get_flags(char *token);
mode_t		get_mode(char *token);
int		*get_fd(t_mod_pack *packet, char *token);
void		get_eof(t_mod_pack *packet, t_btree *tmp);
void		module_call(t_core *core, t_btree *root);
t_btree		*manage_module_call(t_core *core, int ret, t_btree *tmp);
int		execute_cmd(t_core *core, t_mod_pack *packet, t_module *mods);
int		pipe_operation(t_core *core, t_mod_pack *pack, t_module *mods);
int		semicolon_operation(t_core *core, t_mod_pack *packet,
				    t_module *mods);
int		simple_close_chevron_operation(t_core *core, t_mod_pack *pack,
					       t_module *mods);
int		double_close_chevron_operation(t_core *core, t_mod_pack *pack,
					       t_module *mods);
int		simple_open_chevron_operation(t_core *core, t_mod_pack *pack,
					      t_module *mods);
int		double_open_chevron_operation(t_core *core, t_mod_pack *packet,
				      t_module *mods);
int		and_operation(t_core *core, t_mod_pack *packet, t_module *mods);
int		or_operation(t_core *core, t_mod_pack *packet, t_module *mods);

#endif /* !CORE_H_ */
