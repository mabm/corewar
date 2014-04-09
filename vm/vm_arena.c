/*
** vm_arena.c for  in /home/nicolas/Workspace/Corewar/vm
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Tue Apr  8 11:57:41 2014 Nicolas Ades
** Last update Wed Apr  9 22:55:01 2014 Geoffrey Merran
*/

#include "vm_arena.h"

int	increase_pc(int pc, int i)
{
  pc = (pc + i) % MEM_SIZE;
  return (pc);
}

void	execute_instru(t_proc *proc, t_arena *arena, inst *instruction)
{
  if (arena->arena[proc->pc] > 0 && arena->arena[proc->pc] <= 1)
    {
      proc->pc = increase_pc(proc->pc,
			     instruction[arena->arena[proc->pc] - 1](proc, arena));
    }
  else
    proc->pc = increase_pc(proc->pc, 1);
}

void		execute_procs(t_proc **proc, t_arena *arena, inst *instruction)
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
  t_champ	*tmp_ch;

  if ((cycles->current_cycle % cycles->cycle_to_die) == 0)
    {
      tmp = proc;
      while (tmp != NULL)
	{
	  if (tmp->alive == 0)
	    del_proc(tmp);
	  tmp_ch = champ;
	  while (tmp_ch != NULL)
	    {
	      if (tmp->alive == tmp_ch->id)
		tmp_ch->live++;
	      tmp_ch = tmp_ch->next;
	    }
	  tmp = tmp->next;
	}
      if (one_winner(proc, champ))
      	return (1);
      cycles->cycle_to_die -= CYCLE_DELTA;
    }
  return (0);
}

void		launch_battle(t_arena *arena, t_cycles *cycles, t_champ *champs)
{
  t_fighter	fighters;
  t_win		win;
  int		winner;
  inst		*instruction;

  winner = 0;
  fighters.champs = champs;
  init_proc(&fighters.procs, fighters.champs);
  instruction = get_instr();
  init_window(&win);
  init_color(&win, fighters.champs);
  aff_champions(&win, fighters.champs);
  while (cycles->current_cycle != (cycles->cycle_max + 1) && !winner)
    {
      execute_procs(&fighters.procs, arena, instruction);
      aff_window(&win, arena, &fighters, cycles);
      cycles->current_cycle++;
      winner = is_winner(fighters.procs, fighters.champs, cycles);
    }
  who_win(champs);
  free_battle(instruction, &win, &fighters.procs);
}
