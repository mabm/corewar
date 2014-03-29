/*
** main.c for main in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Mar 25 16:39:29 2014 Geoffrey Merran
** Last update Sat Mar 29 19:35:42 2014 Geoffrey Merran
*/

#include "main_vm.h"

void		init_all(int ac, char **av)
{
  unsigned char	*arena;
  t_champ	*champs;
  t_cycles	cycles;

  champs = NULL;
  init_cycle(&cycles);
  init_arena(&arena);
  vm_pars(ac, av, &cycles, &champs);
}

int	main(int ac, char **av)
{
  if (ac > 1)
    init_all(ac, av);
  else
    my_printf(VM_USAGE);
  return (0);
}
