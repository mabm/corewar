/*
** write.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:29:01 2014 Jeremy Mediavilla
** Last update Mon Apr  7 11:45:23 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		dir_data_condition(int fd, t_conv *conv, int flag)
{
  if (flag == 1)
    conv->value = 0;
  write(fd, &conv->octets[3], 1);
  write(fd, &conv->octets[2], 1);
  write(fd, &conv->octets[1], 1);
  write(fd, &conv->octets[0], 1);
}

void		write_reg_data(char *str, int *i, t_conv *conv, int fd)
{
  int		j;
  int		k;
  char		tmp[64];

  j = *i;
  k = 0;
  if (str[*i] == 'r' && '0' <= str[*i + 1] &&
      str[*i + 1] <= '9')
    {
      memset(tmp, 0, 64);
      while (str[j] != ',' && str[j])
	tmp[k++] = str[j++];
      conv->value = atoi(&tmp[1]);
      printf(">> Registre : %s -> %x (%d) (1 Octet)\n", tmp,
	     conv->octets[0], conv->value);
      write(fd, &conv->octets[0], 1);
      *i += 1;
    }
}

void		write_undir_data(char *str, int *i, t_conv *conv, int fd)
{
  char		tmp[64];
  int		j;
  int		k;

  j = *i;
  k = 0;
  if ('0' <= str[*i] && str[*i] <= '9' && str[*i - 1] == ',')
    {
      memset(tmp, 0, 64);
      while (str[j] != ',' && str[j] && '0' <= str[j] && str[j] <= '9')
	tmp[k++] = str[j++];
      conv->value = atoi(&tmp[1]);
      printf(">> Indirect : %s -> %x (%d) (4 Octets)\n", tmp,
	     conv->octets[0], conv->value);
      dir_data_condition(fd, conv, 0);
    }
}

void		write_dir_data(char *str, int *i, t_conv *conv, int fd)
{
  char		tmp[64];
  int		j;
  int		k;

  j = *i;
  k = 0;
  if (str[*i] == '%')
    {
      memset(tmp, 0, 64);
      while (str[j] != ',' && str[j])
	tmp[k++] = str[j++];
      conv->value = atoi(&tmp[1]);
      printf(">> Direct : %s -> %x (4 Octets)\n", tmp, conv->octets[0]);
      if (str[*i + 1] != ':')
	dir_data_condition(fd, conv, 0);
      else
	dir_data_condition(fd, conv, 0);
      while (str[*i + 1] != ',' && str[*i + 1] != '\0')
	(*i)++;
    }
}

void		write_data(int ibase, char *str, int fd)
{
  int		i;
  t_conv	*conv;

  conv = malloc(sizeof(*conv));
  i = ibase;
  while (str[i])
    {
      write_reg_data(str, &i, conv, fd);
      write_dir_data(str, &i, conv, fd);
      write_undir_data(str, &i, conv, fd);
      if (str[i] != '\0')
	i++;
    }
  printf("\n>>------ Next line ------<<\n");
}
