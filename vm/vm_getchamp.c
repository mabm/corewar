/*
** vm_getchamp.c for vm_getchamp in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Mar 26 11:51:37 2014 Geoffrey Merran
** Last update Wed Apr  2 17:04:21 2014 Geoffrey Merran
*/

#include "vm_getchamp.h"

void		fill_champ(t_champ *champ, int fd, unsigned char *arena)
{
  char		*buffer;
  int		ret;

  buffer = my_xmalloc(BUFFER_SIZE * sizeof(char));
  my_memset(buffer, 0, BUFFER_SIZE);
  if ((ret = xread(fd, buffer, (BUFFER_SIZE - 1))) > 0)
    {
      champ->header.magic = get_magic(buffer);
      get_name(buffer, champ->header.prog_name);
      get_comment(buffer, champ->header.comment);
      write_champ_in(buffer, champ->address, arena, ret);
      free(buffer);
    }
}

void		load_champs(t_champ **champs, unsigned char *arena)
{
  t_champ	*tmp;
  int		fd;

  tmp = *champs;
  while (tmp != NULL)
    {
      my_printf("\nLoading champion n°%d\n\n", tmp->id);
      fd = xopen(tmp->name, O_RDONLY, 0);
      fill_champ(tmp, fd, arena);
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
  tmp->address = -1;
  tmp->name = NULL;
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

int		get_nb_champs(t_champ *champs)
{
  t_champ	*tmp;
  int		i;

  i = 0;
  tmp = champs;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}

void	add_champ(t_champ **champ)
{
  if ((*champ) == NULL || (*champ)->carry == 0)
    create_champ(champ);
}
