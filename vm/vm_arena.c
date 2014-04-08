/*
** vm_arena.c for  in /home/nicolas/Workspace/Corewar/vm
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Tue Apr  8 11:57:41 2014 Nicolas Ades
** Last update Tue Apr  8 16:25:04 2014 Geoffrey Merran
*/

#include "vm_arena.h"

void   	aff_arena(unsigned char *arena);

int	increase_pc(int pc, int i)
{
  pc = (pc + i) % MEM_SIZE;
  return (pc);
}

void	execute_instru(t_proc *proc, unsigned char *arena, inst *instruction)
{
  if (arena[proc->pc] > 0 && arena[proc->pc] <= 1)
    {
      proc->pc = increase_pc(proc->pc,
			     instruction[arena[proc->pc] - 1](proc, arena));
    }
  else
    proc->pc = increase_pc(proc->pc, 1);
}

void		execute_procs(t_proc **proc, unsigned char *arena, inst *instruction)
{
  t_proc	*tmp;

  tmp = *proc;
  while (tmp)
    {
      if (tmp->cycle_dodo > 0)
	tmp->cycle_dodo--;
      else
	execute_instru(tmp, arena, instruction);
      tmp = tmp->next;
    }
}

int		is_winner(t_proc *proc, t_champ *champ, t_cycles *cycles)
{
  t_proc	*tmp;

  if ((cycles->current_cycle % cycles->cycle_to_die) == 0)
    {
      tmp = proc;
      while (tmp != NULL)
	{
	  /* check live */
	  tmp = tmp->next;
	}
      cycles->cycle_to_die -= CYCLE_DELTA;
    }
  return (0);
}

void		launch_battle(unsigned char *arena, t_cycles *cycles, t_champ *champs)
{
  t_proc	*proc;
  int		winner;
  inst		*instruction;

  winner = 0;
  init_proc(&proc, champs);
  instruction = get_instr();
  while (cycles->current_cycle != (cycles->cycle_max + 1) && !winner)
    {
      execute_procs(&proc, arena, instruction);
      clear_term();
      my_printf("Current Cycle : %d | Cycle to die : %d\n",
      		cycles->current_cycle, cycles->cycle_to_die);
      /* aff_arena(arena); */
      cycles->current_cycle++;
      winner = is_winner(proc, champs, cycles);
    }
  free(instruction);
}
