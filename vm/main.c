/*
** main.c for main in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Mar 25 16:39:29 2014 Geoffrey Merran
** Last update Wed Apr  2 17:24:43 2014 Geoffrey Merran
*/

#include "main_vm.h"

void		aff_champ(t_champ *champs)
{
  t_champ	*tmp;

  tmp = champs;
  while (tmp != NULL)
    {
      my_printf("id : %d\nname : %s\n", tmp->id, tmp->header.prog_name);
      my_printf("carry : %d, adress : %d\n", tmp->carry, tmp->address);
      my_printf("comment : %s\n", tmp->header.comment);
      tmp = tmp->next;
    }
}

void   	aff_arena(unsigned char *arena)
{
  int  	i;

  i = 0;
  while (i < MEM_SIZE)
    {
      printf("%02X ", arena[i]);
      if ((i + 1) % 32  == 0)
	printf("\n");
      i++;
    }
  printf("\n");
}

/*
** Fonctions d'affichage / debug
*/

void		init_all(int ac, char **av)
{
  unsigned char	*arena;
  t_champ	*champs;
  t_cycles	cycles;

  champs = NULL;
  init_cycle(&cycles);
  init_arena(&arena);
  vm_pars(ac, av, &cycles, &champs);
  init_id(&champs);
  init_addr(&champs);
  load_champs(&champs, arena);
  /* aff_champ(champs); */
  aff_arena(arena);
  free(arena);
}

int	main(int ac, char **av)
{
  if (ac > 1)
    init_all(ac, av);
  else
    my_printf(VM_USAGE);
  return (0);
}
