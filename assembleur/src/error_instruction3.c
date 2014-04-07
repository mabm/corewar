/*
** error_instruction3.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Mon Apr  7 15:28:42 2014 Jeremy Mediavilla
** Last update Mon Apr  7 17:19:50 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		ldi_check_err(t_system *sys, int *values)
{
  (void)sys;
  (void)values;
}

void		fork_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[1] != 0)
    {
      printf("Error on \"fork\" instruction : too many param\n");
      exit(0);
    }
  if (values[0] != 1 || values[0] != 2)
    {
      printf("Error on \"fork\" instruction : first param is not an index\n");
      exit(0);
    }
}

void		lld_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[2] != 0 || values[1] == 0)
    {
      printf("Error on \"lld\" instruction : wrong number of params\n");
      exit(0);
    }
  if (values[1] != 1)
    {
      printf("Error on \"lld\" instruction : second param must be a register\n");
      exit(0);
    }
}

void		lldi_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[2] != 0 || values[1] == 0)
    {
      printf("Error on \"lldi\" instruction : wrong number of params\n");
      exit(0);
    }
  if (values[1] != 1)
    {
      printf("Error on \"lldi\" instruction : second param must be a register\n");
      exit(0);
    }
}

void		lfork_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[1] != 0)
    {
      printf("Error on \"lfork\" instruction : too many param\n");
      exit(0);
    }
  if (values[0] != 1 || values[0] != 2)
    {
      printf("Error on \"lfork\" instruction : first param is not an index\n");
      exit(0);
    }
}
