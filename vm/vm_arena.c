/*
** vm_arena.c for vm_arena in /home/merran_g/work/c_elem/corewar
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Apr  7 16:09:38 2014 Geoffrey Merran
** Last update Mon Apr  7 17:00:08 2014 Geoffrey Merran
*/

#include "vm_arena.h"

void	execute_instru(t_proc *proc, unsigned char *arena)
{
  if (arena[proc->pc] > 0 && arena[proc->pc] <= 17)
    
}

void		execute_procs(t_proc **proc, unsigned char *arena)
{
  t_proc	*tmp;

  tmp = *proc;
  while (tmp)
    {
      if (tmp->cycle_dodo > 0)
	tmp->cycle_dodo--;
      else
	execute_intru(tmp, arena);
      tmp = tmp->next;
    }
}

int	is_winner(t_proc *proc, t_champ *champ, t_cycles *cycles)
{
  if ((cycles->current_cycle % cycles->cycle_to_die) == 0)
    {
      cycles->cycle_to_die -= CYCLE_DELTA;
    }
  return (0);
}

void		launch_battle(unsigned char *arena, t_cycles *cycles, t_champ *champs)
{
  t_proc	*proc;
  int		winner;

  winner = 0;
  init_proc(&proc, champs);
  while (cycles->current_cycle != cycles->cycle_max && !winner)
    {
      execute_procs(&proc, arena);
      my_printf("\rCurrent Cycle : %d | Cycle to die : %d",
		cycles->current_cycle, cycles->cycle_to_die);
      cycles->current_cycle++;
      winner = is_winner(proc, champs, cycles);
    }
}
