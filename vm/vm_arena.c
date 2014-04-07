/*
** vm_arene.c for  in /home/nicolas/Workspace/Corewar/vm
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Thu Mar 27 14:14:19 2014 Nicolas Ades
** Last update Mon Apr  7 16:03:55 2014 Geoffrey Merran
*/

#include "vm_arena.h"



void		execute_procs(t_proc **proc)
{
  t_proc	*tmp;

  tmp = *proc;
  while (tmp)
    {
      if (tmp->cycle_dodo > 0)
	tmp->cycle_dodo--;
      else
	;
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
      execute_procs(&proc);
      my_printf("\rCurrent Cycle : %d | Cycle to die : %d",
		cycles->current_cycle, cycles->cycle_to_die);
      cycles->current_cycle++;
      winner = is_winner(proc, champs, cycles);
    }
}
