/*
** tools.h for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/include/tools
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Sun May 24 16:12:02 2015 Guillaume ROBIN
** Last update Sun May 24 16:12:03 2015 Guillaume ROBIN
*/

#ifndef TOOLS_H_
# define TOOLS_H_

# include <stdlib.h>

# define FREE_LEFT	0
# define FREE_RIGHT	1
# define FREE_BOTH	2
# define NO_FREE	-1

int	put_error(const char *);
int	str_len(const char *);
void	put_str(const char *);
void	put_nbr(int);
void	put_char(const char);
char	*str_dup(const char *);
int	my_puterr(const char *);
int	str_cmp(char *, char *);
char	*str_cat(char *, char *, const char);
int	my_getnbr(const char *);
int	put_str_fd(const int fd, const char *str);
int	char_in_str(const char *str, const char c);
void	put_str_natural(const char *);

#endif /* !TOOLS_H_ */
