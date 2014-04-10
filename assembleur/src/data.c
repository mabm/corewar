/*
** write.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:29:01 2014 Jeremy Mediavilla
** Last update Thu Apr 10 00:29:26 2014 Joris Bertomeu
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
	{
	  if (str[j] >= '0' && str[j] <= '9')
	    tmp[k++] = str[j];
	  j++;
	}
      conv->value = my_getnbr(tmp);
      printf(">> Registre : %s -> %x (%d) (1 Octet)\n", tmp,
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

  j = *i;
  k = 0;
  if ('0' <= str[*i] && str[*i] <= '9')
    {
      memset(tmp, 0, 64);
      while (str[j] != ',' && str[j])
	{
	  if (str[j] && '0' <= str[j] && str[j] <= '9')
	    tmp[k++] = str[j];
	  j++;
	}
      conv->value = my_getnbr(tmp);
      printf(">> Indirect : %s -> %x (%d) (4 Octets)\n", tmp,
	     conv->octets[0], conv->value);
      dir_data_condition(fd, conv, 0);
      while (str[*i] != ',' && str[*i])
	*i += 1;
    }
}

void		write_dir_data(char *str, int *i, t_conv *conv, int fd, t_system *sys)
{
  char		tmp[64];
  int		j;
  int		k;

  k = 0;
  if (str[*i] == '%' && str[*i + 1] != ':')
    {
      j = *i;
      memset(tmp, 0, 64);
      while (str[j] != ',' && str[j])
	tmp[k++] = str[j++];
      conv->value = atoi(&tmp[1]);
      printf(">> Direct : %s -> %x (4 Octets)\n", tmp, conv->octets[0]);
      if (str[*i + 1] != ':')
	dir_data_condition(fd, conv, 0);
      else
	dir_data_condition(fd, conv, 0);
      while (str[*i] != ',' && str[*i] != '\0')
	(*i)++;
    }
  if (str[*i] == '%' && str[*i + 1] == ':')
    {
      j = *i + 2;
      memset(tmp, 0, 64);
      while (str[j] != ',' && str[j])
	tmp[k++] = str[j++];
      tmp[k] = '\0';
      sys->olabels[sys->col].offset = lseek(sys->ins.fd, 0, SEEK_CUR);
      sys->olabels[sys->col].line = sys->start_line;
      sys->olabels[sys->col].name = malloc(strlen(tmp) * sizeof(char));
      strcpy(sys->olabels[sys->col++].name, tmp);
      /* i = 0; */
      /* while (i < sys->cl) */
      /* 	{ */
      /* 	  if (strcmp(sys->labels[i].name, tmp) == 0) */
      /* 	    flag = 1; */
      /* 	  i++; */
      /* 	} */
      /* conv->value = atoi(&tmp[1]); */
      printf(">> Direct : %s -> %x (4 Octets) (Label Call)\n",
	     tmp, conv->octets[0]);
      /* if (str[*i + 1] != ':') */
      /* 	dir_data_condition(fd, conv, 0); */
      /* else */
      dir_data_condition(fd, conv, 1);
      while (str[*i] != ',' && str[*i] != '\0')
	(*i)++;
    }
}

void		write_data(int ibase, char *str, int fd, int line, t_system *sys)
{
  int		i;
  t_conv	*conv;

  conv = malloc(sizeof(*conv));
  i = ibase;
  while (str[i])
    {
      write_reg_data(str, &i, conv, fd);
      write_dir_data(str, &i, conv, fd, sys);
      write_undir_data(str, &i, conv, fd);
      if (str[i] != '\0')
	i++;
    }
  printf("\n>> Line %d\n\n", line + 2);
}
