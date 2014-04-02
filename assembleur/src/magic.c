/*
** magic.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:35:59 2014 Jeremy Mediavilla
** Last update Wed Apr  2 15:36:22 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void	write_magic(int fd)
{
  char	c[4];

  c[0] = 'm';
  c[1] = 'a';
  c[2] = 'b';
  c[3] = 'm';
  write(fd, &c, 4);
  printf(">> Passphrase Wrote : **** ( 4 Octets )\n\n");
}
