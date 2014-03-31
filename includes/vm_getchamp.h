/*
** vm_getchamp.h for vm_getchamp in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Mar 26 11:52:31 2014 Geoffrey Merran
** Last update Mon Mar 31 19:17:13 2014 Geoffrey Merran
*/

#ifndef VM_GETCHAMP_
# define VM_GETCHAMP_
# define BUFFER_SIZE 4096
# include "vm_parser.h"
# include "vm_corewar.h"

void	add_champ(t_champ **champ);
void	load_champs(t_champ **champs, unsigned char *arena);

#endif /* VM_GETCHAMP_ */
