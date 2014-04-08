/*
** vm_instruction.h for vm_instruction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 12:46:20 2014 Geoffrey Merran
** Last update Tue Apr  8 14:34:50 2014 Geoffrey Merran
*/

#ifndef VM_INSTRUCTION_
# define VM_INSTRUCTION_
# include <stdlib.h>
# include "vm_corewar.h"
# include "vm_arena.h"
# include "op.h"
# include "my.h"

typedef int (*instr)(t_proc *, unsigned char *);

instr	*get_instr();
int	live(t_proc *, unsigned char *);
int	ld(t_proc *, unsigned char *);
int	st(t_proc *, unsigned char *);
int	add(t_proc *, unsigned char *);
int	sub(t_proc *, unsigned char *);
int	and(t_proc *, unsigned char *);
int	or(t_proc *, unsigned char *);
int	xor(t_proc *, unsigned char *);
int	zjmp(t_proc *, unsigned char *);
int	ldi(t_proc *, unsigned char *);
int	sti(t_proc *, unsigned char *);
int	vm_fork(t_proc *, unsigned char *);
int	lld(t_proc *, unsigned char *);
int	lldi(t_proc *, unsigned char *);
int	lfork(t_proc *, unsigned char *);
int	aff(t_proc *, unsigned char *);

#endif /* VM_INSTRUCTION */
