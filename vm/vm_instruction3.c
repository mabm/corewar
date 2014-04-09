/*
** vm_instruction3.c for vm_instruction3 in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 14:29:40 2014 Geoffrey Merran
** Last update Wed Apr  9 19:32:57 2014 Geoffrey Merran
*/

#include "vm_instruction.h"

int		ldi(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[10].nbr_cycles;
  return (1);
}

int		sti(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[11].nbr_cycles;
  return (1);
}

int		vm_fork(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[12].nbr_cycles;
  return (1);
}

int		lld(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[13].nbr_cycles;
  return (1);
}

int		lldi(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[14].nbr_cycles;
  return (1);
}
