/*
** vm_init.c for vm_init in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Mar 28 16:00:42 2014 Geoffrey Merran
** Last update Mon Mar 31 18:45:08 2014 Geoffrey Merran
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

int		is_id_possible(t_champ *champs, int id)
{
  t_champ	*tmp;

  tmp = champs;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}

void		init_id(t_champ **champs)
{
  int		id;
  t_champ	*tmp;

  id = 1;
  tmp = *champs;
  while (tmp != NULL)
    {
      while (tmp->id == 0)
	{
	  if (is_id_possible(*champs, id))
	    tmp->id = id;
	  id++;
	}
      tmp = tmp->next;
    }
}
