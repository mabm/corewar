/*
** vm_instruction.h for vm_instruction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 12:46:20 2014 Geoffrey Merran
** Last update Tue Apr  8 23:28:59 2014 Geoffrey Merran
*/

#ifndef VM_INSTRUCTION_
# define VM_INSTRUCTION_
# include <stdlib.h>
# include "vm_corewar.h"
# include "vm_arena.h"
# include "op.h"
# include "my.h"

inst	*get_instr();
int	live(t_proc *, t_arena *);
int	ld(t_proc *, t_arena *);
int	st(t_proc *, t_arena *);
int	add(t_proc *, t_arena *);
int	sub(t_proc *, t_arena *);
int	and(t_proc *, t_arena *);
int	or(t_proc *, t_arena *);
int	xor(t_proc *, t_arena *);
int	zjmp(t_proc *, t_arena *);
int	ldi(t_proc *, t_arena *);
int	sti(t_proc *, t_arena *);
int	vm_fork(t_proc *, t_arena *);
int	lld(t_proc *, t_arena *);
int	lldi(t_proc *, t_arena *);
int	lfork(t_proc *, t_arena *);
int	aff(t_proc *, t_arena *);

#endif /* VM_INSTRUCTION */
