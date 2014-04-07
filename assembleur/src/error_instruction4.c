/*
** error_instruction4.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Mon Apr  7 15:29:25 2014 Jeremy Mediavilla
** Last update Mon Apr  7 17:21:51 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		aff_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[1] != 0)
    {
      printf("Error on \"aff\" instruction : too many params\n");
      exit(0);
    }
  if (values[0] != 1)
    {
      printf("Error on \"aff\" instruction : first param must be a register\\n");
      exit(0);
    }
}
