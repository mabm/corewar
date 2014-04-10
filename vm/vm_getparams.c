/*
** vm_getparams.c for vm_getparams in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Apr 10 01:13:59 2014 Geoffrey Merran
** Last update Thu Apr 10 01:57:25 2014 Geoffrey Merran
*/

#include "vm_getparams.h"

void	get_codage(unsigned char code, char **params, int nb_args)
{
  int	i;
  int	j;

  i = 0;
  while (i < nb_args)
    {
      j = 0;
      params[TYPE_P][i] = 0;
      while (j < 2)
	{
	  if ((code & 128) != 0)
	    params[TYPE_P][i] += my_power_rec(1, 2);
	  code = code << 1;
	  j++;
	}
      i++;
    }
}

char	**get_params(int nb_args, t_arena *arena, int address)
{
  char	**params;
  int	i;

  i = 0;
  params = my_xmalloc(2 * sizeof(char *));
  params[TYPE_P] = my_xmalloc(nb_args * sizeof(char));
  params[VALUE_P] = my_xmalloc(nb_args * sizeof(char));
  get_codage(arena->arena[address], params, nb_args);
  while (i < nb_args)
    printf("%d\n", params[TYPE_P][i++]);
  pause();
  return (params);
}
