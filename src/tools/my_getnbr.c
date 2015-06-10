/*
** my_getnbr.c for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/src/tools
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri May 22 22:28:17 2015 Guillaume ROBIN
** Last update Fri May 22 22:28:17 2015 Guillaume ROBIN
*/

static void	my_iter_nbr(const char *str, int *i, int *neg)
{
  while (str[*i] != '\0' && (str[*i] == '-' || str[*i] == '+'))
    {
      if (str[*i] == '-')
	*neg = *neg + 1;
      *i = *i + 1;
    }
}

int	my_getnbr(const char *str)
{
  int	n;
  int	neg;
  int	i;
  int	tmp;

  n = 0;
  neg = 0;
  i = 0;
  my_iter_nbr(str, &i, &neg);
  tmp = i;
  while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    {
      if (neg % 2 == 0)
	n = n * 10 + (str[i] - '0');
      else
	n = n * 10 - (str[i] - '0');
      i = i + 1;
      if ((i - tmp) > 10 || (neg % 2 == 0 && n < 0) || (neg % 2 == 1 && n > 0))
	return (0);
    }
  return (n);
}
