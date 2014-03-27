/*
** vm_pars.c for  in /home/nicolas/Workspace/Corewar/vm
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed Mar 26 11:40:53 2014 Nicolas Ades
** Last update Thu Mar 27 19:22:08 2014 Geoffrey Merran
*/

#include "vm_parser.h"

int	dump_opt(int i, int ac, char **av)
{
  int	nbr_cycle;


  nbr_cycle = -1;
  if (my_strcmp(av[i], "-dump") == 0)
    {
      if (i + 1 < ac)
	{
	  nbr_cycle = my_getnbr(av[i + 1]);
	  if (nbr_cycle <= 0)
	    my_error("-dump error : -dump must be positive\n");
	  else
	    {
	      /* il faut stocker nbr_cycle */
	    }
	}
      else
	my_error("-dump error : You must give a value with the option\n");
    }
  return (i);
}

int	a_opt(int i, int ac, char **av)
{
  int	ld_add;

  if (my_strcmp(av[i], "-a") == 0)
    {
      if (i + 1 < ac)
	{
	  ld_add = my_getnbr(av[i + 1]);
	  if (ld_add < 0 || ld_add > MEM_SIZE - 1)
	    {
	      my_error("-a error : Value must be contain in memory\n");
	    }
	}
      else
	my_error("-a : You must give a value with the option\n");
    }
  return (i);
}

int	n_opt(int i, int ac, char **av)
{
  int	prog_nb;

  if (my_strcmp(av[i], "-n") == 0)
    {
      if (i + 1 < ac)
	{
	  prog_nb = my_getnbr(av[i + 1]);
	  /* a finir */
	}
      else
	{
	  prog_nb = 1;
	  my_error("-n error : Default value set as 1\n");
	}
    }
  return (i);
}

int	get_cor(int i, int ac, char **av)
{
  int	k;

  k = my_strlen(av[i]);
  if (k < 4)
    {
      my_error("champ error : Invalid champion\n");
      return (i);
    }
  if (my_strcmp(&(av[i][k - 4]), ".cor") == 0)
    {
      /* stockage du champion et incrémentation du compteur de champion */
    }
  else
    {
      my_error("champ error : Invalid champion\n");
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
