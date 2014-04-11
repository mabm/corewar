/*
** vm_instruction.c for vm_instruction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 12:45:16 2014 Geoffrey Merran
** Last update Fri Apr 11 20:45:07 2014 Geoffrey Merran
*/

#include "vm_instruction.h"

inst	*get_instr()
{
  inst	*instruction;

  instruction = my_xmalloc(17 * sizeof(*instruction));
  instruction[0] = NULL;
  instruction[1] = ld;
  instruction[2] = st;
  instruction[3] = add;
  instruction[4] = sub;
  instruction[5] = and;
  instruction[6] = or;
  instruction[7] = xor;
  instruction[8] = zjmp;
  instruction[9] = ldi;
  instruction[10] = sti;
  instruction[11] = vm_fork;
  instruction[12] = lld;
  instruction[13] = lldi;
  instruction[14] = lfork;
  instruction[15] = aff;
  instruction[16] = NULL;
  return (instruction);
}

int		live(t_proc *proc, t_arena *arena, t_champ **champ)
{
  int		i;
  int		j;
  t_conv	conv;
  t_champ	*tmp;

  proc->pc = increase_pc(proc->pc, 1);
  i = proc->pc;
  j = 0;
  while (j < 4)
    {
      conv.octet[3 - j] = arena->arena[i];
      i = increase_pc(i, 1);
      j++;
    }
  proc->alive = conv.integer;
  tmp = *champ;
  while (tmp != NULL)
    {
      if (proc->alive == tmp->id)
	tmp->live++;
      tmp = tmp->next;
    }
  my_printf("Live : %d at %d\n", conv.integer, proc->pc);
  proc->cycle_dodo = op_tab[0].nbr_cycles;
  return (4);
}

int		ld(t_proc *proc, t_arena *arena)
{
  char		**params;

  params = get_params(op_tab[1].nbr_args, arena, increase_pc(proc->pc, 1));
  free_params(params, op_tab[1].nbr_args);
  proc->cycle_dodo = op_tab[1].nbr_cycles;
  return (1);
}

int		st(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[2].nbr_cycles;
  return (1);
}

int		add(t_proc *proc, t_arena *arena)
{
  char		**params;
  int		jump;
  int		r1;
  int		r2;

  params = get_params(op_tab[3].nbr_args, arena, increase_pc(proc->pc, 1));
  if (!is_valid_reg(params[TYPE_P][0], params[1][0]) ||
      !is_valid_reg(params[TYPE_P][1], params[2][0]) ||
      !is_valid_reg(params[TYPE_P][2], params[3][0]))
    return (err_instr(params, op_tab[3].nbr_args));
  r1 = proc->reg[params[1][0] - 1];
  r2 = proc->reg[params[2][0] - 1];
  proc->reg[params[3][0] - 1] = r1 + r2;
  free_params(params, op_tab[3].nbr_args);
  jump = 2 + get_nb_jump(params[TYPE_P], op_tab[3].nbr_args);
  proc->carry = 1;
  proc->cycle_dodo = op_tab[3].nbr_cycles;
  return (jump);
}
