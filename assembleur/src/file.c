/*
** file.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:33:49 2014 Jeremy Mediavilla
** Last update Wed Apr  2 15:34:28 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		register_condition(int *i, char *c, int *cmptr, char *str)
{
  if (str[*i] == 'r' && '0' <= str[*i + 1] &&
      str[*i + 1] <= '9')
    {
      if (*cmptr == 0)
	*c += 0x40;
      else if (*cmptr == 1)
	*c += 0x10;
      else if (*cmptr == 2)
	*c += 0x4;
      else if (*cmptr == 3)
	*c += 0x1;
      *i += 1;
    }
}

void		direct_condition(int *i, char *c, int *cmptr, char *str)
{
  if (str[*i] == '%')
    {
      if (*cmptr == 0)
	*c += 0x80;
      else if (*cmptr == 1)
	*c += 0x20;
      else if (*cmptr == 2)
	*c += 0x8;
      else if (*cmptr == 3)
	*c += 0x2;
      while (str[*i + 1] != ',' && str[*i + 1] != '\0')
	(*i)++;
    }
}

void		indirect_condition(int *i, char *c, int *cmptr, char *str)
{
  if ('0' <= str[*i] && str[*i] <= '9' && str[*i - 1] == ',')
    {
      if (*cmptr == 0)
	*c += 0xC0;
      else if (*cmptr == 1)
	*c += 0x30;
      else if (*cmptr == 2)
	*c += 0xC;
      else if (*cmptr == 3)
	*c += 0x3;
    }
}

void		write_to_file(char *str, int fd)
{
  char		c;
  int		i;
  int		cmptr_param;
  int		ibase;
  int		ret_chck;

  c = 0;
  i = 0;
  cmptr_param = 0;
  ibase = 0;
  ret_chck = 0;
  while (str[i])
    {
      if (ret_chck == 0)
	ret_chck = check_instruction(str, &c, &i, &ibase, fd);
      if (str[i] == ',')
	cmptr_param++;
      register_condition(&i, &c, &cmptr_param, str);
      direct_condition(&i, &c, &cmptr_param, str);
      indirect_condition(&i, &c, &cmptr_param, str);
      i++;
    }
  if (ret_chck == 1)
    write(fd, &c, 1);
  write_data(ibase, str, fd);
}
