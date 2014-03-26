/*
** vm_pars.c for  in /home/nicolas/Workspace/Corewar/vm
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed Mar 26 11:40:53 2014 Nicolas Ades
** Last update Wed Mar 26 11:55:49 2014 Nicolas Ades
*/

#include "vm_parser.h"

struct s_flag	g_flags[] =
  {"-a", &do_a},
  {"-dump", &do_dump},
  {"-n" &do_n},
  {NULL, NULL};

void	vm_pars(char **tab)
{
  int	k;

  k = 0;
}
