/*
** vm_getchamp.h for vm_getchamp in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Mar 26 11:52:31 2014 Geoffrey Merran
** Last update Thu Apr  3 12:42:44 2014 Geoffrey Merran
*/

#ifndef VM_GETCHAMP_
# define VM_GETCHAMP_
# define BUFFER_SIZE 3717
# include "vm_parser.h"
# include "vm_corewar.h"

void	add_champ(t_champ **champ);
void	load_champs(t_champ **champs, unsigned char *arena);
void	fill_champ(t_champ *champ, int fd, unsigned char *arena);
void	write_champ_in(unsigned char *, int address, unsigned char *arena, int);
int    	get_nb_champs(t_champ *champs);
int	get_magic(unsigned char *buffer);
void	get_name(unsigned char *buffer, char prog_name[]);
void	get_comment(unsigned char *buffer, char comment[]);

#endif /* VM_GETCHAMP_ */
