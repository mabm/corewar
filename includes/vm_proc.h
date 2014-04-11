/*
** vm_proc.h for vm_proc in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Apr  7 13:27:30 2014 Geoffrey Merran
** Last update Fri Apr 11 21:52:27 2014 Geoffrey Merran
*/

#ifndef VM_PROC_
# define VM_PROC_
# include <stdlib.h>
# include "vm_corewar.h"
# include "my.h"

void   	add_proc(t_proc **proc, t_champ *champ);
t_proc	*del_proc(t_proc *proc, t_proc **start);
void	init_proc(t_proc **proc, t_champ *champ);
int    	get_nb_proc(t_proc *proc);

#endif /* VM_PROC_ */
