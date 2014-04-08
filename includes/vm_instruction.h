/*
** vm_instruction.h for vm_instruction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 12:46:20 2014 Geoffrey Merran
** Last update Tue Apr  8 13:07:23 2014 Geoffrey Merran
*/

#ifndef VM_INSTRUCTION_
# define VM_INSTRUCTION_
# include "vm_corewar.h"

typedef int (*instr)(t_proc *, unsigned char);

int	live(t_proc *, unsigned char *);

#endif /* VM_INSTRUCTION */
