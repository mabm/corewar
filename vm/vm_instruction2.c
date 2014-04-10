/*
** vm_instruction2.c for vm_instruction2 in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 14:27:51 2014 Geoffrey Merran
** Last update Fri Apr 11 01:36:13 2014 Geoffrey Merran
*/

#include "vm_instruction.h"

int		sub(t_proc *proc, t_arena *arena)
{
  char		**params;
  int		jump;
  int		r1;
  int		r2;

  params = get_params(op_tab[4].nbr_args, arena, increase_pc(proc->pc, 1));
  if (!is_valid_reg(params[TYPE_P][0], params[1][0]) ||
      !is_valid_reg(params[TYPE_P][1], params[2][0]) ||
      !is_valid_reg(params[TYPE_P][2], params[3][0]))
    return (err_instr(params, op_tab[5].nbr_args));
  r1 = proc->reg[params[1][0] - 1];
  r2 = proc->reg[params[2][0] - 1];
  proc->reg[params[3][0] - 1] = r1 - r2;
  free_params(params, op_tab[4].nbr_args);
  jump = 2 + get_nb_jump(params[TYPE_P], op_tab[4].nbr_args);
  proc->carry = 1;
  proc->cycle_dodo = op_tab[4].nbr_cycles;
  return (jump);
}

int		and(t_proc *proc, t_arena *arena)
{
  char		**params;
  int		jump;
  int		r1;
  int		r2;

  params = get_params(op_tab[5].nbr_args, arena, increase_pc(proc->pc, 1));
  if (!is_valid_reg(params[TYPE_P][2], params[3][0]))
    return (err_instr(params, op_tab[5].nbr_args));
  r1 = get_val(params[TYPE_P][0], params[1], arena, proc->reg);
  r2 = get_val(params[TYPE_P][1], params[2], arena, proc->reg);
  proc->reg[params[3][0] - 1] = r1 & r2;
  my_printf("and %d in %d\n", r1 + r2, (params[3][0] - 1));
  free_params(params, op_tab[5].nbr_args);
  jump = 2 + get_nb_jump(params[TYPE_P], op_tab[5].nbr_args);
  proc->carry = 1;
  proc->cycle_dodo = op_tab[5].nbr_cycles;
  return (jump);
}

int		or(t_proc *proc, t_arena *arena)
{
  char		**params;
  int		jump;
  int		r1;
  int		r2;

  params = get_params(op_tab[6].nbr_args, arena, increase_pc(proc->pc, 1));
  if (!is_valid_reg(params[TYPE_P][2], params[3][0]))
    return (err_instr(params, op_tab[6].nbr_args));
  r1 = get_val(params[TYPE_P][0], params[1], arena, proc->reg);
  r2 = get_val(params[TYPE_P][1], params[2], arena, proc->reg);
  proc->reg[params[3][0] - 1] = r1 | r2;
  free_params(params, op_tab[6].nbr_args);
  jump = 2 + get_nb_jump(params[TYPE_P], op_tab[6].nbr_args);
  proc->carry = 1;
  proc->cycle_dodo = op_tab[6].nbr_cycles;
  return (jump);
}

int		xor(t_proc *proc, t_arena *arena)
{
  char		**params;
  int		jump;
  int		r1;
  int		r2;

  params = get_params(op_tab[7].nbr_args, arena, increase_pc(proc->pc, 1));
  if (!is_valid_reg(params[TYPE_P][2], params[3][0]))
    return (err_instr(params, op_tab[7].nbr_args));
  r1 = get_val(params[TYPE_P][0], params[1], arena, proc->reg);
  r2 = get_val(params[TYPE_P][1], params[2], arena, proc->reg);
  proc->reg[params[3][0] - 1] = r1 ^ r2;
  free_params(params, op_tab[7].nbr_args);
  jump = 2 + get_nb_jump(params[TYPE_P], op_tab[7].nbr_args);
  proc->carry = 1;
  proc->cycle_dodo = op_tab[7].nbr_cycles;
  return (jump);
}

int		zjmp(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[8].nbr_cycles;
  return (1);
}

