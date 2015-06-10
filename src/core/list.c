/*
** list.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue May 12 17:51:54 2015 Guillaume ROBIN
** Last update Sun May 24 14:11:07 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <stdlib.h>
#include "list.h"

t_list		*list_end_insert(t_list *old, char *data)
{
  t_list	*new;
  t_list	*tmp;

  tmp = old;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if ((new = malloc(sizeof(*new))) == NULL)
    return (old);
  new->data = data;
  new->next = NULL;
  if (tmp != NULL)
    tmp->next = new;
  else if (tmp == NULL)
    return (new);
  return (old);
}

t_list		*list_insert(t_list *old, char *data)
{
  t_list	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (old);
  new->data = data;
  new->next = old;
  return (new);
}

void		list_free(t_list *list)
{
  t_list	*tmp;

  while (list != NULL)
    {
      tmp = list->next;
      free(list->data);
      free(list);
      list = tmp;
    }
}

int		list_size(t_list *list)
{
  int		count;
  t_list	*tmp;

  count = 0;
  tmp = list;
  while (tmp != NULL)
    {
      count++;
      tmp = tmp->next;
    }
  return (count);
}
