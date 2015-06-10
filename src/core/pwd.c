/*
** pwd.c<2> for mysh in /home/robin_f/Projects/PSU_2014_minishell2
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.net>
** 
** Started on  Tue Feb 24 10:34:33 2015 Guillaume ROBIN
** Last update Sun May 24 14:19:19 2015 Guillaume ROBIN
*/

/*
** Norme: check!
*/

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "list.h"
#include "tools.h"
#include "const.h"
#include "module_packet.h"

static t_list	*found_dir(t_list *pwd, struct stat *prev)
{
  DIR		*flux;
  struct dirent	*dir;
  struct stat	tmp;
  int		bool;

  if ((flux = opendir(STR_POINT)) != NULL)
    {
      bool = 1;
      while ((dir = readdir(flux)) != NULL && bool)
	{
	  if (lstat(dir->d_name, &tmp) == -1)
	    bool = 0;
	  if (bool && prev->st_ino == tmp.st_ino
	      && prev->st_dev == tmp.st_dev)
	    pwd = list_insert(pwd, str_dup(dir->d_name));
	}
      closedir(flux);
    }
  return (pwd);
}

static int	get_size(t_list *list)
{
  t_list	*elt;
  int		count;

  count = 0;
  elt = list;
  while (elt != NULL)
    {
      count += str_len(elt->data);
      elt = elt->next;
    }
  if (count > 0)
    count += list_size(list);
  return (count);
}

static char	*init_buffer(t_list *list, int *i)
{
  char		*buff;
  int		size;

  size = get_size(list) + 2;
  if (size - 2 <= 0 || !(buff = malloc(sizeof(char) * size)))
    return (NULL);
  buff[0] = CHAR_SLASH;
  buff[size - 1] = END_STR;
  *i = 1;
  return (buff);
}

static char	*get_pwd(t_list *list)
{
  t_list	*elt;
  char		*pwd;
  int		i;
  int		j;

  pwd = init_buffer(list, &i);
  if ((elt = list) != NULL && pwd != NULL)
    {
      while (elt != NULL)
	{
	  j = 0;
	  while (elt->data[j] != END_STR)
	    {
	      pwd[i] = elt->data[j];
	      i += 1;
	      j += 1;
	    }
	  pwd[i] = CHAR_SLASH;
	  i += 1;
	  elt = elt->next;
	}
    }
  list_free(list);
  return (pwd);
}

char		*my_pwd(void)
{
  struct stat	cur;
  struct stat	prev;
  t_list	*pwd;
  int		found;
  char		*path;

  found = 0;
  pwd = NULL;
  while (found == 0)
    {
      if (lstat(STR_POINT, &prev) == -1)
	return (NULL);
      if (chdir(STR_DPOINT) == -1)
	return (NULL);
      if (lstat(STR_DPOINT, &cur) == -1)
	return (NULL);
      if (prev.st_ino == cur.st_ino && prev.st_dev == cur.st_dev)
	found = 1;
      else
	pwd = found_dir(pwd, &prev);
    }
  path = get_pwd(pwd);
  return (path);
}
