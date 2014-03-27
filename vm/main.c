/*
** main.c for main in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Mar 25 16:39:29 2014 Geoffrey Merran
** Last update Thu Mar 27 19:09:30 2014 Geoffrey Merran
*/

#include "main_vm.h"

int	main(int ac, char **av)
{
  if (ac > 1)
    vm_pars(ac, av);
  else
    my_printf(VM_USAGE);
  return (0);
}
