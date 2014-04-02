/*
** aff.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:14:22 2014 Jeremy Mediavilla
** Last update Wed Apr  2 15:27:31 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		affbin(unsigned n)
{
  unsigned	bit;
  unsigned	mask;
  int		i;

  bit = 0;
  i = 0;
  mask = 1;
  while (i < 32)
    {
      bit = (n & mask) >> i;
      printf("%d", bit) ;
      mask <<= 1 ;
      i++;
    }
  printf("\n");
}

void		aff_error(char *msg)
{
  printf(msg);
  exit (0);
}

void		aff_info(t_system *system, char *name)
{
  if (system->name == 0 || system->comment == 0)
    aff_error("One file is corrupt !\n");
  printf("--------------\n\nNom du fichier : %s\n", name);
  printf("Nom du Chamion : %s\n", system->name);
  printf("Commentaire du Champion : %s\n", system->comment);
  printf("\n--------------\n");
}
