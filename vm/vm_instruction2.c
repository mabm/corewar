/*
** vm_instruction2.c for vm_instruction2 in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 14:27:51 2014 Geoffrey Merran
** Last update Wed Apr  9 19:30:58 2014 Geoffrey Merran
*/

#include "vm_instruction.h"

int		sub(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[4].nbr_cycles;
  return (1);
}

int		and(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[5].nbr_cycles;
  return (1);
}

int		or(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[6].nbr_cycles;
  return (1);
}

int		xor(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[7].nbr_cycles;
  return (1);
}

int		zjmp(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[8].nbr_cycles;
  return (1);
}

