/*
** strcmp.c for  in /home/mediav_j/corewar/tmp
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Mar 26 18:29:36 2014 Jeremy Mediavilla
** Last update Wed Mar 26 18:30:11 2014 Jeremy Mediavilla
*/

#include "base.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] < s2[i])
	return (-1);
      if (s1[i] > s2[i])
	return (1);
      i++;
    }
  if (s1[i] < s2[i])
    return (-1);
  if (s1[i] > s2[i])
    return (1);
  return (0);
}
