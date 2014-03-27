/*
** main.c for  in /home/mediav_j/corewar/tmp
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Mar 26 17:56:46 2014 Jeremy Mediavilla
** Last update Thu Mar 27 11:14:23 2014 Jeremy Mediavilla
*/

#include "base.h"

int		main(int ac, char **av)
{
  (void)ac;
  printf("%s\n", convert_base_int(atoi(av[1]), av[2]));
  return (0);
}
