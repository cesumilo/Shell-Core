/*
** list.h for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue May 12 17:44:53 2015 Guillaume ROBIN
** Last update Wed May 13 15:09:40 2015 Caroline PEREZ
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list
{
  char		*data;
  struct s_list	*next;
}		t_list;

/*
** Methods.
*/
t_list		*list_insert(t_list *old, char *data);
t_list		*list_end_insert(t_list *old, char *data);
int		list_size(t_list *list);
void		list_free(t_list *list);

#endif /* !LIST_H_ */
