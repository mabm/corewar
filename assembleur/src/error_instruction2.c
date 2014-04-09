/*
** error_instruction2.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Mon Apr  7 15:28:07 2014 Jeremy Mediavilla
** Last update Tue Apr  8 23:38:49 2014 Joris Bertomeu
*/

#include "assembleur.h"
#include "gnl.h"

void		st_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[2] != 0 || values[1] == 0)
    {
      printf("Error on \"st\" instruction : wrong number of params\n");
      exit(0);
    }
}

void		add_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[0] != 1 || values[1] != 1 || values[2] != 1)
    {
      printf("Error on \"add\" instruction : all params must be register\n");
      exit(0);
    }
}

void		sub_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[0] != 1 || values[1] != 1 || values[2] != 1)
    {
      printf("Error on \"sub\" instruction : all params must be register\n");
      exit(0);
    }
}

void		or_check_err(t_system *sys, int *values)
{
  (void)sys;
    if (values[2] != 1)
    {
      printf("Error on \"or\" instruction : last param is not a register\n");
      exit(0);
    }
}

void		xor_check_err(t_system *sys, int *values)
{
  (void)sys;
    if (values[2] != 1)
    {
      printf("Error on \"xor\" instruction : last param is not a register\n");
      exit(0);
    }
}
