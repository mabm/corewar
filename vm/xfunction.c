/*
** xfunction.c for xfunction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Mar 26 13:21:27 2014 Geoffrey Merran
** Last update Wed Mar 26 13:25:34 2014 Geoffrey Merran
*/

#include "xfunction.h"

int	xopen(char *pathname, int flags, mode_t mode)
{
  int	a;

  if ((a = open(pathname, flags, mode)) == -1)
    {
      my_printf("Open error\n");
      exit(1);
    }
  return (a);
}
