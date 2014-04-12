/*
** write.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:29:01 2014 Jeremy Mediavilla
** Last update Sat Apr 12 18:07:10 2014 Joris Bertomeu
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
      my_memset(tmp, 0, 64);
      while (str[j] != ',' && str[j])
	{
	  if (str[j] >= '0' && str[j] <= '9')
	    tmp[k++] = str[j];
	  j++;
	}
      conv->value = my_getnbr(tmp);
      my_printf(">> Registre : %s -> %d (%d) (1 Octet)\n", tmp,
	     conv->octets[0], conv->value);
      write(fd, &conv->octets[0], 1);
      *i = j;
    }
}

void		write_undir_data(char *str, int *i, t_conv *conv, int fd)
{
  char		tmp[64];
  int		j;
  int		k;
  int		neg;

  neg = 1;
  j = *i;
  k = 0;
  if (('0' <= str[*i] && str[*i] <= '9') ||
      ('0' <= str[*i + 1] && str[*i + 1] <= '9' && str[*i] == '-'))
    {
      my_memset(tmp, 0, 64);
      while (str[j] != ',' && str[j])
	{
	  if (str[j] == '-')
	    neg = -1;
	  if (str[j] && '0' <= str[j] && str[j] <= '9')
	    tmp[k++] = str[j];
	  j++;
	}
      conv->value = my_getnbr(tmp) * neg;
      my_printf(">> Indirect : %s -> %d (%d) (4 Octets)\n", tmp,
	     conv->octets[0], conv->value);
      dir_data_condition(fd, conv, 0);
      while (str[*i] != ',' && str[*i])
	*i += 1;
    }
}

void		write_dir_data(char *str, int *i, t_conv *conv, t_system *sys)
{
  char		tmp[64];
  int		j;
  int		neg;

  neg = 1;
  sys->kf = 0;
  if (str[*i] == '%' && str[*i + 1] != ':')
    {
      j = *i;
      my_memset(tmp, 0, 64);
      while (str[j] != ',' && str[j])
	{
	  if ('0' <= str[j] && str[j] <= '9')
	    tmp[sys->kf++] = str[j];
	  else if (str[j] == '-')
	    neg = -1;
	  j++;
	}
      conv->value = my_getnbr(tmp) * neg;
      my_printf(">> Direct : %s -> %d (4 Octets)\n", tmp, conv->value);
      dir_data_condition(sys->ins.fd, conv, 0);
      while (str[*i] != ',' && str[*i] != '\0')
	(*i)++;
    }
  if (str[*i] == '%' && str[*i + 1] == ':')
    j = param_pt(str, sys, conv, i);
}

void		write_data(int ibase, char *str, int line, t_system *sys)
{
  int		i;
  t_conv	*conv;

  conv = malloc(sizeof(*conv));
  my_memset(conv->octets, '\0', 4);
  i = ibase;
  while (str[i])
    {
      write_reg_data(str, &i, conv, sys->ins.fd);
      write_dir_data(str, &i, conv, sys);
      write_undir_data(str, &i, conv, sys->ins.fd);
      if (str[i] != '\0')
	i++;
    }
  my_printf("\n>> Line %d\n\n", line + 2);
}
