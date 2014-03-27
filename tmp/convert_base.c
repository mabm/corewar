/*
** my_convert_base.c for  in /home/mediav_j/piscine/Piscine-C-Jour_08/ex_02
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Thu Oct 10 16:31:42 2013 Jeremy Mediavilla
** Last update Thu Mar 27 11:12:03 2014 Jeremy Mediavilla
*/

#include "base.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char		*my_revstr(char *str)
{
  int		i;
  int		j;
  int		len;
  char		*final;

  len = my_strlen(str);
  final = malloc(len * sizeof(char));
  i = 0;
  j = len - 1;
  while (i < len)
    {
      final[i] = str[j];
      j--;
      i++;
    }
  return (final);
}

char		*convert_base_str(char *nbr, char *base_from, char *base_to)
{
  int		i;
  int		j;
  char		*str;

  i = 0;
  str = malloc(sizeof(char) * 300);
  j = my_getnbr_base(nbr, base_from);
  while (j > 0)
    {
      str[i] = base_to[j % my_strlen(base_to)];
      j = j / my_strlen(base_to);
      i++;
    }
  str[i] = '\0';
  str = my_revstr(str);
  return (str);
}

char		*convert_base_int(int nb, char *base_to)
{
  int		i;
  int		j;
  char		*str;

  i = 0;
  str = malloc(sizeof(char) * 300);
  j = nb;
  while (j > 0)
    {
      str[i] = base_to[j % my_strlen(base_to)];
      j = j / my_strlen(base_to);
      i++;
    }
  str[i] = '\0';
  str = my_revstr(str);
  return (str);
}

