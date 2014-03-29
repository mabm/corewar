/*
** vm_getchamp.c for vm_getchamp in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Mar 26 11:51:37 2014 Geoffrey Merran
** Last update Sat Mar 29 20:13:16 2014 Geoffrey Merran
*/

#include "vm_getchamp.h"

void		create_champ(t_champ **champ)
{
  t_champ	*tmp;
  int		i;

  tmp = my_xmalloc(sizeof(*tmp));
  tmp->id = 0;
  tmp->address = -1;
  tmp->name = NULL;
  tmp->comment = NULL;
  tmp->carry = 0;
  i = 0;
  while (i < REG_NUMBER)
    tmp->reg[i++] = 0;
  tmp->next = *champ;
  if (*champ != NULL)
    (*champ)->prev = tmp;
  *champ = tmp;
}

void	add_champ(t_champ **champ)
{
  if ((*champ) == NULL || (*champ)->carry == 1)
    {
      create_champ(champ);
    }
}
