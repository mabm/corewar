/*
** vm_corewar.h for vm_corewar.h in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Mar 26 12:00:22 2014 Geoffrey Merran
** Last update Wed Apr  2 11:03:30 2014 Geoffrey Merran
*/

#ifndef VM_COREWAR_
# define VM_COREWAR_
# define MAGIC_NUMBER 413
# include "op.h"

typedef struct		s_champ
{
  int			id;
  header_t		header;
  int			address;
  char			*name;
  int			carry;
  int			cursor;
  char			reg[REG_NUMBER];
  struct s_champ	*next;
  struct s_champ	*prev;
}			t_champ;

typedef	struct	s_cycles
{
  int		nbr_live;
  int		cycle_to_die;
  int		current_cycle;
  int		cycle_max;
}		t_cycles;

#endif /* VM_COREWAR_ */
