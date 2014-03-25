/*
** my_getnbr.c for my_getnbr in /home/merran_g/work/c_piscine/createlib/files.c
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Oct 21 19:01:39 2013 Geoffrey Merran
** Last update Thu Nov 14 15:52:10 2013 Geoffrey Merran
*/

#include "my.h"

int     get_number(char *str, int i, int neg)
{
  int   nb;
  int   save;

  nb = 0;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      save = nb;
      if (save > (nb * 10 + (str[i] - '0')))
        return (0);
      nb = nb * 10 + (str[i++] - '0');
    }
  if (neg % 2 == 1)
    nb = nb * -1;
  return (nb);
}

int     my_getnbr(char *str)
{
  int   i;
  int   nb;
  int   neg;

  i = 0;
  neg = 0;
  while (str[i])
    {
      if (str[i] == '-')
        neg++;
      if (!my_isdigit(str[i]))
	return (0);
      if (str[i] >= '0' && str[i] <= '9')
        {
          nb = get_number(str, i, neg);
          return (nb);
        }
      i++;
    }
  return (0);
}
