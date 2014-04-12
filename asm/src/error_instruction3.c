/*
** error_instruction3.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Mon Apr  7 15:28:42 2014 Jeremy Mediavilla
** Last update Sat Apr 12 16:02:49 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		ldi_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[0] != 2 && values[0] != 3)
    {
      my_printf("Error on \"ldi\" instruction : \
first param must be an index\n");
      exit(0);
    }
  if (values[1] != 2 && values[1] != 3)
    {
      my_printf("Error on \"ldi\" instruction : \
second param must be an index\n");
      exit(0);
    }
}

void		fork_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[1] != 0)
    {
      my_printf("Error on \"fork\" instruction : too many param\n");
      exit(0);
    }
  if (values[0] == 1)
    {
      my_printf("Error on \"fork\" instruction : \
first param is not an index\n");
      exit(0);
    }
}

void		lld_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[2] != 0 || values[1] == 0 || values[0] == 0)
    {
      my_printf("Error on \"lld\" instruction : wrong number of params\n");
      exit(0);
    }
  if (values[1] != 1)
    {
      my_printf("Error on \"lld\" instruction : \
second param must be a register\n");
      exit(0);
    }
}

void		lldi_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[0] != 2 || values[0] != 3)
    {
      my_printf("Error on \"lldi\" instruction : \
first param must be an index\n");
      exit(0);
    }
  if (values[1] != 2 || values[1] != 3)
    {
      my_printf("Error on \"lldi\" instruction : \
second param must be an index\n");
      exit(0);
    }
}

void		lfork_check_err(t_system *sys, int *values)
{
  (void)sys;
  if (values[1] != 0)
    {
      my_printf("Error on \"lfork\" instruction : too many param\n");
      exit(0);
    }
  if (values[0] == 1)
    {
      my_printf("Error on \"lfork\" instruction : \
first param is not an index\n");
      exit(0);
    }
}
