/*
** vm_proc.c for vm_proc in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Apr  7 13:26:57 2014 Geoffrey Merran
** Last update Wed Apr  9 17:32:14 2014 Geoffrey Merran
*/

#include "vm_proc.h"

void		add_proc(t_proc **proc, t_champ *champ)
{
  t_proc	*tmp;
  int		i;

  tmp = my_xmalloc(sizeof(*tmp));
  tmp->id = champ->id;
  tmp->pc = champ->address;
  tmp->carry = 0;
  tmp->alive = 0;
  tmp->cycle_dodo = 0;
  i = 0;
  while (i < REG_NUMBER)
    tmp->reg[i++] = 0;
  tmp->reg[0] = tmp->id;
  tmp->next = *proc;
  tmp->prev = NULL;
  if (*proc != NULL)
    (*proc)->prev = tmp;
  *proc = tmp;
}

void		del_proc(t_proc *proc)
{
  t_proc	*tmp;
  t_proc	*next;
  t_proc	*prev;

  next = proc->next;
  prev = proc->prev;
  if (next != NULL || prev != NULL)
    {
      if (next != NULL)
	next->prev = prev;
      if (prev != NULL)
	prev->next = next;
    }
  tmp = proc;
  proc = next;
  free(tmp);
}

void		init_proc(t_proc **proc, t_champ *champ)
{
  t_champ	*tmp;

  *proc = NULL;
  tmp = champ;
  while (tmp)
    {
      add_proc(proc, tmp);
      tmp = tmp->next;
    }
}
