/*
** my_puterr.c for my_puterr in /home/merran_g/work/c_elem/PSU_2013_minishell1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Feb 18 12:16:38 2014 Geoffrey Merran
** Last update Tue Feb 18 12:17:03 2014 Geoffrey Merran
*/

#include <unistd.h>
#include "my.h"

void	my_puterr(char *err)
{
  write(2, err, my_strlen(err));
}
