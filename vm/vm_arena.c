/*
** vm_arena.c for  in /home/nicolas/Workspace/Corewar/vm
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Tue Apr  8 11:57:41 2014 Nicolas Ades
** Last update Wed Apr  9 00:54:09 2014 Geoffrey Merran
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
	    my_printf("mort\n");
	  /* suppr l'elem tmp */
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

/* void	aff_arena(unsigned char *c_arena) */
/* { */
/*   int	i; */

/*   i = 0; */
/*   while (i < MEM_SIZE) */
/*     { */
/*       printf("%d ", c_arena[i]); */
/*       if (((i + 1) % 32) == 0) */
/* 	printf("\n"); */
/*       i++; */
/*     } */
/* } */

void		launch_battle(t_arena *arena, t_cycles *cycles, t_champ *champs)
{
  t_proc	*proc;
  SDL_Surface	*screen;
  int		winner;
  inst		*instruction;

  winner = 0;
  init_proc(&proc, champs);
  instruction = get_instr();
  init_window(&screen);
  while (cycles->current_cycle != (cycles->cycle_max + 1) && !winner)
    {
      execute_procs(&proc, arena, instruction);
      aff_arena(screen, arena, proc);
      /* my_printf("Current Cycle : %d | Cycle to die : %d\n", */
      /* 		cycles->current_cycle, cycles->cycle_to_die); */
      cycles->current_cycle++;
      winner = is_winner(proc, champs, cycles);
    }
  SDL_Quit();
  free(instruction);
}
