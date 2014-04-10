/*
** vm_instruction3.c for vm_instruction3 in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 14:29:40 2014 Geoffrey Merran
** Last update Fri Apr 11 01:34:56 2014 Geoffrey Merran
*/

#include "vm_instruction.h"

int		ldi(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[9].nbr_cycles;
  return (1);
}

int		sti(t_proc *proc, t_arena *arena)
{
  char		**params;
  t_conv	reg;
  int		addr;
  int		jump;

  params = get_params(op_tab[10].nbr_args, arena, increase_pc(proc->pc, 1));
  if (!is_valid_reg(params[TYPE_P][0], params[1][0]))
    return (err_instr(params, op_tab[10].nbr_args));
  reg.integer = proc->reg[params[1][0] - 1];
  addr = get_val(params[TYPE_P][1], params[2], arena, proc->reg);
  addr += get_val(params[TYPE_P][2], params[3], arena, proc->reg);
  write_vm(arena, ((addr + proc->pc) % MEM_SIZE), reg, proc->id);
  jump = 2 + get_nb_jump(params[TYPE_P], op_tab[10].nbr_args);
  my_printf("store index %d at %d\n", reg.integer,
	    ((addr + proc->pc) % MEM_SIZE));
  free_params(params, op_tab[10].nbr_args);
  proc->cycle_dodo = op_tab[10].nbr_cycles;
  return (jump);
}

int		vm_fork(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[11].nbr_cycles;
  return (1);
}

int		lld(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[12].nbr_cycles;
  return (1);
}

int		lldi(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[13].nbr_cycles;
  return (1);
}
