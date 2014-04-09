/*
** error_instruction1.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Mon Apr  7 15:26:21 2014 Jeremy Mediavilla
** Last update Wed Apr  9 17:49:25 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		sti_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[2] == 0)
    {
      printf("Error on \"sti\" instruction : wrong number of params\n");
      exit(0);
    }
}

void		and_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[2] == 0)
    {
      printf("Error on \"and\" instruction : wrong number of param\n");
      exit(0);
    }
  if (values[2] != 1)
    {
      printf("Error on \"and\" instruction : last param is not a register\n");
      exit(0);
    }
}

void		ld_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[2] != 0 || values[1] == 0 || values[0] == 0)
    {
      printf("Error on \"ld\" instruction : wrong number of params\n");
      exit(0);
    }
  if (values[1] != 1)
    {
      printf("Error on \"ld\" instruction : second param must be a register\n");
      exit(0);
    }
}

void		live_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[1] != 0 || values[0] == 0)
    {
      printf("Error on \"live\" instruction : worng number of param\n");
      exit(0);
    }
  if (values[0] == 1)
    {
      printf("Error on \"live\" instruction : first param must be an index\n");
      exit(0);
    }
}

void		zjmp_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[1] != 0)
    {
      printf("Error on \"zjmp\" instruction : too many param\n");
      exit(0);
    }
  if (values[0] == 1)
    {
      printf("Error on \"zjmp\" instruction : first param is not an index\n");
      exit(0);
    }
}
