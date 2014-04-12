/*
** aff.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:14:22 2014 Jeremy Mediavilla
** Last update Sat Apr 12 15:16:16 2014 Joris Bertomeu
*/

#include "assembleur.h"
#include "gnl.h"

void		aff_error(char *msg)
{
  my_printf(msg);
  exit (0);
}

void		aff_info(t_system *system, char *name)
{
  if (system->name == 0 || system->comment == 0)
    aff_error("One file is corrupt !\n");
  my_printf("--------------\n\nNom du fichier : %s\n", name);
  my_printf("Nom du Chamion : %s\n", system->name);
  my_printf("Commentaire du Champion : %s\n", system->comment);
  my_printf("\n--------------\n");
}
