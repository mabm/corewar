/*
** my_free.c for my_free in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Apr  7 10:19:02 2014 Geoffrey Merran
** Last update Mon Apr  7 10:43:48 2014 Geoffrey Merran
*/

#include "my_free.h"

void		free_champ(t_champ **champs)
{
  t_champ	*tmp;

  while (*champs)
    {
      tmp = (*champs)->next;
      free(*champs);
      *champs = tmp;
    }
}
