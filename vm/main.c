/*
** main.c for main in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Mar 25 16:39:29 2014 Geoffrey Merran
** Last update Tue Apr  8 23:32:54 2014 Geoffrey Merran
*/

#include "main_vm.h"

void		init_all(int ac, char **av)
{
  t_arena	*arena;
  t_champ	*champs;
  t_cycles	cycles;

  champs = NULL;
  arena = my_xmalloc(sizeof(*arena));
  init_cycle(&cycles);
  init_arena(arena);
  vm_pars(ac, av, &cycles, &champs);
  init_id(&champs);
  init_addr(&champs);
  load_champs(&champs, arena);
  launch_battle(arena, &cycles, champs);
  free(arena->arena);
  free(arena->color);
  free(arena);
  free_champ(&champs);
}

int	main(int ac, char **av)
{
  xtgetent(NULL, "xterm");
  if (ac > 1)
    init_all(ac, av);
  else
    my_printf(VM_USAGE);
  return (EXIT_SUCCESS);
}
