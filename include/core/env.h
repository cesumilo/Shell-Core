/*
** env.h for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Apr 29 16:23:14 2015 Guillaume ROBIN
** Last update Mon May 11 16:14:39 2015 Guillaume ROBIN
*/

#ifndef ENV_H_
# define ENV_H_

typedef struct	s_env
{
  char		*data;
  struct s_env	*next;
}		t_env;

/*
** Env methods.
*/
t_env		*env_load(void);
t_env		*env_insert(t_env *old, char *var);
void		env_free(t_env *env);
int		env_size(t_env *env);
char		**env_convert(t_env *env);
void		env_draw(t_env *env);
char		*get_env(t_env *env, const char *name);
t_env		*unset_env(t_env *env, char *name);
t_env		*set_env(t_env *env, char *name, char *var);

#endif /* !ENV_H_ */
