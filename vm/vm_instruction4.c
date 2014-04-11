/*
** vm_instruction4.c for vm_instruction4.c in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 14:31:16 2014 Geoffrey Merran
** Last update Fri Apr 11 23:18:22 2014 Geoffrey Merran
*/

#include "vm_instruction.h"

int		lfork(t_proc *proc, t_arena *arena)
{
  (void) arena;
  proc->cycle_dodo = op_tab[14].nbr_cycles;
  return (1);
}

int		aff(t_proc *proc, t_arena *arena)
{
  char		**params;
  int		reg;

  params = get_params(op_tab[15].nbr_args, arena, increase_pc(proc->pc, 1));
  if (!is_valid_reg(params[TYPE_P][0], params[1][0]))
    return (err_instr(params, op_tab[15].nbr_args));
  reg = proc->reg[params[1][0] - 1];
  my_printf("%c\n", (reg % 256));
  free_params(params, op_tab[15].nbr_args);
  proc->cycle_dodo = op_tab[15].nbr_cycles;
  return (1);
}

void		live_champ(t_proc *proc, t_champ **champ)
{
  t_champ	*tmp;

  tmp = *champ;
  while (tmp != NULL)
    {
      if (proc->alive == tmp->id)
	tmp->live++;
      tmp = tmp->next;
    }
}
