/*
** vm_getparams3.c for vm_getparams in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Apr 11 00:16:23 2014 Geoffrey Merran
** Last update Fri Apr 11 00:25:04 2014 Geoffrey Merran
*/

#include "vm_getparams.h"

int	get_nb_jump(char *type, int nb_args)
{
  int	i;
  int	jump;

  i = 0;
  jump = 0;
  while (i < nb_args)
    {
      if (type[i] == A_REG)
	jump += 1;
      if (type[i] == A_DIR || type[i] == A_IND)
	jump += 4;
      i++;
    }
  return (jump);
}
