/*
** main.c for main in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Mar 25 16:39:29 2014 Geoffrey Merran
** Last update Tue Mar 25 17:25:01 2014 Geoffrey Merran
*/

#include "main_vm.h"

void	vm_parse(char **tab)
{
  
}

int	main(int ac, char **av)
{
  if (ac > 1)
    vm_parse(av);
  else
    my_printf(VM_USAGE);
  return (0);
}
