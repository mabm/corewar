/*
** vm_arene.c for  in /home/nicolas/Workspace/Corewar/vm
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Thu Mar 27 14:14:19 2014 Nicolas Ades
<<<<<<< HEAD
** Last update Mon Apr  7 15:37:58 2014 Nicolas Ades
=======
** Last update Mon Apr  7 14:26:12 2014 Geoffrey Merran
>>>>>>> 1af4f088dd5b33598850d477e65730ef204bc5a9
*/

#include "vm_arena.h"

void		execute_proc(t_proc **proc)
{
  t_proc	*tmp;

  tmp = *proc;
}

void		launch_battle(unsigned char *arena, t_cycles *cycles, t_champ *champs)
{
  t_proc	*proc;
  int		winner;

  winner = 0;
  init_proc(&proc, champs);
  while (cycles->current_cycle != cycles->cycle_max && !winner)
    {
      execute_proc(&proc);
      my_printf("\rCurrent Cycle : %d | Cycle to die : %d",
		cycles->current_cycle, cycles->cycle_to_die);
      cycles->current_cycle++;
      if ((cycles->current_cycle % cycles->cycle_to_die) == 0)
	cycles->cycle_to_die -= CYCLE_DELTA;
    }
}
