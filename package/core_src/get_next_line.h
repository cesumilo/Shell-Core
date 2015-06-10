/*
** get_next_line.h for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/include/tools
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Sun May 24 16:12:19 2015 Guillaume ROBIN
** Last update Sun May 24 16:12:20 2015 Guillaume ROBIN
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <stdlib.h>

# define ABS(x) ((x) < 0 ? (x * (-1)) : (x))
# define READ_MAX 4096

char	*get_next_line(const int, int *);

#endif /* !GET_NEXT_LINE_H_ */
