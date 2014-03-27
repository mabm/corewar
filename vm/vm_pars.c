/*
** vm_pars.c for  in /home/nicolas/Workspace/Corewar/vm
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed Mar 26 11:40:53 2014 Nicolas Ades
** Last update Thu Mar 27 14:09:11 2014 Nicolas Ades
*/

#include "vm_parser.h"

int	dump_opt(int i, int ac, char **av)
{
  int	nbr_cycle;


  nbr_cycle = -1;
  if (my_strcmp(av[i], "-dump") == 0)
    {
      if (i + 2 < ac)
	{
	  nbr_cycle = my_getnbr(av[i + 1]);
	  if (nbr_cycle <= 0)
	    my_putstr("-dump must be positive\n");
	  else
	    /* il faut stocker nbr_cycle */
	}
      else
	my_putstr("You must give a value with the option\n");
    }
  return (i + 1);
} 

int	a_opt(int i, int ac, char **av)
{
  int	ld_add;

  if (my_strcmp(av[i], "-a") == 0)
    {
      if (i + 2 < ac)
	{
	  ld_add = my_getnbr(av[i + 1]);
	  if (ld_add < 0 || ld_add > MEM_SIZE - 1)
	    {
	      my_putstr("Value must be contain in memory\n");
	      exit(-1);
	    }
	}
      else
	my_putstr("You must give a value with the option\n");
    }
  return (i + 1);
} 

int	n_opt(int i, int ac, char **av)
{
  int	prog_nb;

  if (my_strcmp(av[i], "-n") == 0)
    {
      if (i + 2 < ac)
	{
	  prog_nb = my_getnbr(av[i + 1]);
	  /* a finir */
	}
      else
	my_putstr("You must give a value with the option\n");
    }
  return (i + 1);
} 

int	get_cor(int i, int ac, char **av)
{
  int	k;

  k = my_strlen(av[i]);
  if (k < 4)
    {
      my_putstr("Invalid champion\n");
      return (i);
    }
  if (my_strcmp(&(av[i][k - 4]), ".cor") == 0)
    {
      /* stockage du champion et incrémentation du compteur de champion */
    }
  else
    {
      my_putstr("Invalid champion\n");
      return (i);
    }
  return (i);
} 

void	vm_pars(int ac, char **av)
{
  int	i;

  i = 1;
  while (i <= ac)
    {
      i = dump_opt(i, ac, av);
      i = a_opt(i, ac, av);
      i = n_opt(i, ac, av);
      i = get_cor(i, ac, av);
      i++;
    }
}
