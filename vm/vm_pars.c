/*
** vm_pars.c for  in /home/nicolas/Workspace/Corewar/vm
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed Mar 26 11:40:53 2014 Nicolas Ades
** Last update Wed Mar 26 12:20:31 2014 Nicolas Ades
*/

#include "vm_parser.h"

struct s_flag	g_flags[] =
  {"-a", &do_a},
  {"-dump", &do_dump},
  {"-n" &do_n},
  {NULL, NULL};

void	do_a(char *opt)
{

}

void	do_dump(char *opt)
{

}

void	do_n(char *opt)
{

}

void	check_cor(char *file)
{

}

void	vm_pars(char **tab)
{
  int	k;

  k = 0;
  while (g_flags.flag != NULL)
    {
      if (my_strcmp(g_flags.flag[k], tab[i]) == 0)
	{
	  g_flags[k].fct(tab[i + 1]);
	}
      else
	check_cor(tab[i]);
      k++;
    }
}
