/*
** module_call.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/module
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri May 22 22:29:59 2015 Guillaume ROBIN
** Last update Wed Jun 10 14:32:07 2015 Guillaume ROBIN
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "module.h"
#include "const.h"
#include "tools.h"

static int	count_modules(void)
{
  DIR		*dir;
  int		count;
  struct dirent	*file;

  if (!(dir = opendir(MODULES_PATH)))
    return (0);
  count = 0;
  while ((file = readdir(dir)))
    {
      if (str_len(file->d_name) >= 4
	  && str_cmp(&(file->d_name[str_len(file->d_name) - 3]), ".so")
	  == EQUAL)
	count++;
    }
  if (closedir(dir) == ERROR)
    my_puterr(ERR_CLOSE_DIR);
  return (count);
}

static int	input_data(t_module *tab, int *i, char *file)
{
  void		*handle;
  void		(*get_name)(char **);
  int		(*start)(t_mod_pack *);
  char		*path;

  if (str_len(file) >= 4 && str_cmp(&(file[str_len(file) - 3]), ".so") == EQUAL)
    {
      path = str_cat(MODULES_PATH, file, NO_FREE);
      if (!path || !(handle = dlopen(path, RTLD_NOW)))
	return (my_puterr(dlerror()));
      if (!(start = (int (*)(t_mod_pack *))dlsym(handle, "module_start")))
	return (my_puterr(dlerror()));
      if (!(get_name = (void (*)(char **))dlsym(handle, "module_name")))
	return (my_puterr(dlerror()));
      free(path);
      tab[*i].handle = handle;
      get_name(&(tab[*i].name));
      tab[*i].start = start;
      tab[*i].is_enabled = TRUE;
      *i += 1;
    }
  return (NO_ERR);
}

static int	fill_module_tab(t_module *tab, int size)
{
  DIR		*dir;
  struct dirent	*file;
  int		i;

  if ((dir = opendir(MODULES_PATH)))
    {
      i = 0;
      while (i < size && (file = readdir(dir)))
	{
	  if (input_data(tab, &i, file->d_name) == ERROR)
	    return (my_puterr(ERR_GET_MODULE));
	}
      if (closedir(dir) == ERROR)
	my_puterr(ERR_CLOSE_DIR);
    }
  else
    my_puterr(ERR_OPENDIR);
  return (NO_ERR);
}

t_module	*get_modules(void)
{
  int		nb_mods;
  t_module	*tab;

  nb_mods = count_modules();
  if (!(tab = malloc(sizeof(*tab) * (nb_mods + 1))))
    return (NULL);
  tab[nb_mods].start = NULL;
  tab[nb_mods].name = NULL;
  if (fill_module_tab(tab, nb_mods) == ERROR)
    {
      free(tab);
      return (NULL);
    }
  return (tab);
}

void	close_modules(t_module *tab)
{
  int	i;
  if (tab != NULL)
    {
      i = 0;
      while (tab && tab[i].start != NULL)
	{
	  dlclose(tab[i].handle);
	  free(tab[i].name);
	  i++;
	}
      free(tab);
    }
}
