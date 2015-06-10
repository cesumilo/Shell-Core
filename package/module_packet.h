/*
** module_packet.h for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Apr 30 17:03:02 2015 Guillaume ROBIN
** Last update Tue Jun  9 22:50:09 2015 Guillaume ROBIN
*/

#ifndef MODULE_PACKET_H_
# define MODULE_PACKET_H_

# include "env.h"

typedef struct		s_jobs
{
  int			id;
  int			pid;
  char			*cmd;
  struct s_jobs		*next;
}			t_jobs;

typedef struct		s_module_packet
{
  char			id;
  int			err;
  int			ac;
  char			**av;
  char			**env;
  t_env			**env_list;
  int			pipe[2];
  int			p_read;
  int			p_write;
  int			rd_write;
  int			rd_read;
  int			fd_read;
  char			is_alias;
  char			free_needed;
  char			*eof;
  char			is_dchv;
  void			*data;
  t_jobs		**jobs;
  char			*name;
}			t_mod_pack;

/*
** Management.
*/
int		check_signal(int pid, int status, t_mod_pack *packet);
void		signal_handler(void);
void		signal_handler_parent(int child);
void		pipe_management(t_mod_pack *packet);
void		pipe_management_parent(t_mod_pack *packet);
void		redirection_management(t_mod_pack *packet);
void		redirection_management_close(t_mod_pack *packet);
int		manage_return(t_mod_pack *packet);

/*
** Jobs Control.
*/
t_jobs		*jobs_insert(t_jobs *old, int pid, char **av);
t_jobs		*jobs_remove(t_jobs *list, int id);
int		jobs_get_pid(t_jobs *list, int id);
void		jobs_free(t_jobs *list);

/*
** Providing specials methods.
*/
char		*my_pwd(void);

#endif /* !MODULE_PACKET_H_ */
