/*
** vm_instruction4.c for vm_instruction4.c in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 14:31:16 2014 Geoffrey Merran
** Last update Wed Apr  9 19:33:43 2014 Geoffrey Merran
*/

#include "vm_instruction.h"

int		lfork(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[16].nbr_cycles;
  return (1);
}

int		aff(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[17].nbr_cycles;
  return (1);
}
