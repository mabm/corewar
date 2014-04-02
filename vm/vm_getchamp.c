/*
** vm_getchamp.c for vm_getchamp in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Mar 26 11:51:37 2014 Geoffrey Merran
** Last update Mon Mar 31 19:22:03 2014 Geoffrey Merran
*/

#include "vm_getchamp.h"

int		fill_champ(t_champ *champ, int fd)
{
  char		*buffer;

  buffer = my_xmalloc(BUFFER_SIZE * sizeof(char));
  my_memset(buffer, 0, BUFFER_SIZE);
  while (xread(fd, buffer, (BUFFER_SIZE - 1)) > 0)
    {
      my_putstr(buffer);
      my_memset(buffer, 0, BUFFER_SIZE);
    }
  free(buffer);
  return (0);
}

void		load_champs(t_champ **champs, unsigned char *arena)
{
  t_champ	*tmp;
  int		fd;
  int		pos;

  tmp = *champs;
  while (tmp != NULL)
    {
      fd = xopen(tmp->name, O_RDONLY, 0);
      pos = fill_champ(tmp, fd);
      close(fd);
      tmp = tmp->next;
    }
}

void		create_champ(t_champ **champ)
{
  t_champ	*tmp;
  int		i;

  tmp = my_xmalloc(sizeof(*tmp));
  tmp->id = 0;
  tmp->magic = 0;
  tmp->address = -1;
  tmp->name = NULL;
  tmp->comment = NULL;
  tmp->carry = -1;
  tmp->cursor = -1;
  i = 0;
  while (i < REG_NUMBER)
    tmp->reg[i++] = 0;
  tmp->next = *champ;
  tmp->prev = NULL;
  if (*champ != NULL)
    (*champ)->prev = tmp;
  *champ = tmp;
}

void	add_champ(t_champ **champ)
{
  if ((*champ) == NULL || (*champ)->carry == 0)
    {
      create_champ(champ);
    }
}
