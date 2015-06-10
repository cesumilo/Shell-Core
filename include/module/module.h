/*
** module.h for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/include/module
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri May 22 22:38:08 2015 Guillaume ROBIN
** Last update Wed Jun 10 14:10:08 2015 Guillaume ROBIN
*/

#ifndef MODULE_H_
# define MODULE_H_

# include "module_packet.h"

/*
** Règles:
**
** Chaque nouvelle gestion d'erreur venant des modules
** doit absoluement commencer par la synthaxe "ERR_" puis le nom.
*/

# define NB_MODULES	15

# define ERR_M_MALLOC	-1
# define ERR_NOT_FOUND	0
# define ERR_FOUND	2
# define ERR_SHUTDOWN	1
# define ERR_SD_PIPE	1764
# define ERR_FREE	1765

# define DEF_SHUTDOWN(x)(x != ERR_SD_PIPE ? x : ERR_SD_PIPE)

typedef struct	s_module
{
  char		*name;
  int		(*start)(t_mod_pack *packet);
  void		*handle;
  char		is_enabled;
}		t_module;

typedef int	(*t_mod_start)(t_mod_pack *packet);

/*
** Core methods.
*/
t_module	*get_modules(void);
void		close_modules(t_module *);

#endif /* !MODULE_H_ */
