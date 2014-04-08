/*
** vm_arena.h for  in /home/nicolas/Workspace/Corewar/includes
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Tue Apr  1 11:50:43 2014 Nicolas Ades
** Last update Tue Apr  8 16:09:30 2014 Geoffrey Merran
*/

#ifndef VM_ARENA_
# define VM_ARENA_
# include "vm_corewar.h"
# include "vm_proc.h"
# include "vm_instruction.h"
# include "term_fct.h"
# include "my_printf.h"

int	increase_pc(int pc, int i);
void	launch_battle(unsigned char *arena, t_cycles *cycles, t_champ *champs);

#endif /* VM_ARENA_ */
