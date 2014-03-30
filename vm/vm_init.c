/*
** vm_init.c for vm_init in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Mar 28 16:00:42 2014 Geoffrey Merran
** Last update Sat Mar 29 19:02:21 2014 Geoffrey Merran
*/

#include "vm_init.h"

void	init_cycle(t_cycles *cycles)
{
  cycles->nbr_live = 0;
  cycles->cycle_to_die = CYCLE_TO_DIE;
  cycles->current_cycle = 1;
  cycles->cycle_max = -1;
}

void	init_arena(unsigned char **arena)
{
  int	i;

  *arena = my_xmalloc(MEM_SIZE * sizeof(char));
  i = 0;
  while (i < MEM_SIZE)
    (*arena)[i++] = 0;
}
