/*
** xfunctions.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sat Apr 12 18:19:19 2014 Jeremy Mediavilla
** Last update Sat Apr 12 18:31:26 2014 Jeremy Mediavilla
*/

#include "gnl.h"
#include "assembleur.h"

void		*xmalloc(size_t size)
{
  void		*tmp;

  if ((tmp = malloc(size)) == NULL)
    {
      my_putstr("Malloc error\n");
      exit(0);
    }
  return (tmp);
}

int		xopen(const char *pathname, int flags)
{
  int		fd;

  if ((fd = open(pathname, flags)) == -1)
    {
      my_putstr("Open error\n");
      exit(0);
    }
  return (fd);
}
