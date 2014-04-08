/*
** vm_instruction.c for vm_instruction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 12:45:16 2014 Geoffrey Merran
** Last update Tue Apr  8 14:33:20 2014 Geoffrey Merran
*/

#include "vm_instruction.h"

instr	*get_instr()
{
  instr	*instruction;

  instruction = my_xmalloc(17 * sizeof(*instruction));
  instruction[0] = live;
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

int		live(t_proc *proc, unsigned char *arena)
{
  int		i;
  int		j;
  t_conv	conv;

  proc->pc = increase_pc(proc->pc, 1);
  i = proc->pc;
  j = 0;
  while (j < 4)
    {
      conv.octet[3 - j] = arena[i];
      i = increase_pc(i, 1);
      j++;
    }
  proc->alive = conv.integer;
  proc->cycle_dodo = op_tab[0].nbr_cycles;
  return (4);
}

int		ld(t_proc *proc, unsigned char *arena)
{
  return (1);
}

int		st(t_proc *proc, unsigned char *arena)
{
  return (1);
}

int		add(t_proc *proc, unsigned char *arena)
{
  return (1);
}
