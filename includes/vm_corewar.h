/*
** vm_corewar.h for vm_corewar.h in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Mar 26 12:00:22 2014 Geoffrey Merran
** Last update Wed Mar 26 13:55:14 2014 Geoffrey Merran
*/

#ifndef VM_COREWAR_
# define VM_COREWAR_
# include "op.h"

typedef struct		s_champ
{
  int			id;
  char			*name;
  char			*comment;
  int			carry;
  char			reg[REG_NUMBER];
  struct s_champ	*next;
  struct s_champ	*prev;
}			t_champ;

typedef	struct	s_cycles
{
  int		nbr_live;
  int		cycle_to_die;
  int		current_cycle;
}		t_cycles;

#endif /* VM_COREWAR_ */
