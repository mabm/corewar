/*
** vm_getchamp2.c for vm_getchamp2 in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Apr  2 10:48:31 2014 Geoffrey Merran
** Last update Wed Apr  2 12:30:33 2014 Geoffrey Merran
*/

#include "vm_getchamp.h"

int	get_magic(char *buffer)
{
  int	i;
  int	magic;

  i = 0;
  magic = 0;
  while (i < 4)
    magic += buffer[i++];
  if (magic == MAGIC_NUMBER)
    {
      my_printf("Magic number ok!\n");
      return (magic);
    }
  my_error("Champion error : Wrong magic number. USE OUR ASM FAGG !\n");
  return (-1);
}

void	get_name(char *buffer, char prog_name[])
{
  int	i;

  i = 4;
  while (i < PROG_NAME_LENGTH + 4)
    {
      prog_name[i - 4] = buffer[i];
      i++;
    }
  prog_name[PROG_NAME_LENGTH] = '\0';
  my_printf("Name ok !\n");
}

void	get_comment(char *buffer, char comment[])
{
  int	i;
  int	pos;

  pos = 4 + PROG_NAME_LENGTH;
  i = pos;
  while (i < (pos + COMMENT_LENGTH))
    {
      printf("%c\n", buffer[i]);
      comment[i - pos] = buffer[i];
      i++;
      sleep(1);
    }
  comment[COMMENT_LENGTH] = '\0';
  my_printf("Comment ok !\n");
}
