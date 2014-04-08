/*
** vm_arena.h for  in /home/nicolas/Workspace/Corewar/includes
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Tue Apr  1 11:50:43 2014 Nicolas Ades
** Last update Tue Apr  8 23:24:36 2014 Geoffrey Merran
*/

#ifndef VM_ARENA_
# define VM_ARENA_
# include "vm_corewar.h"
# include "vm_proc.h"
# include "vm_instruction.h"
# include "sdl_xfunction.h"
# include "term_fct.h"
# include "aff.h"
# include "my_printf.h"

int	increase_pc(int pc, int i);
int    	is_winner(t_proc *proc, t_champ *champ, t_cycles *cycles);
int    	one_winner(t_proc *proc, t_champ *champ);
void	execute_instru(t_proc *proc, t_arena *arena, inst *instruction);
void	execute_procs(t_proc **proc, t_arena *arena, inst *instruction);
void	launch_battle(t_arena *arena, t_cycles *cycles, t_champ *champs);

#endif /* VM_ARENA_ */
