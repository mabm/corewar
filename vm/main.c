/*
** main.c for main in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Mar 25 16:39:29 2014 Geoffrey Merran
** Last update Wed Mar 26 11:40:43 2014 Nicolas Ades
*/

#include "main_vm.h"

int	main(int ac, char **av)
{
  if (ac > 1)
    vm_parse(av);
  else
    my_printf(VM_USAGE);
  return (0);
}
