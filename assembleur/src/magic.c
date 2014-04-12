/*
** magic.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:35:59 2014 Jeremy Mediavilla
** Last update Sat Apr 12 13:58:18 2014 Joris Bertomeu
*/

#include "assembleur.h"
#include "gnl.h"

void	write_magic(int fd)
{
  char	c[4];
  t_conv	conv;

  c[0] = 'm';
  c[1] = 'a';
  c[2] = 'b';
  c[3] = 'm';
  write(fd, &c, 4);
  printf(">> Passphrase Wrote : **** ( 4 Octets )\n\n");
  conv.value = 0;
  write(fd, &conv.octets, 4);
}

void	do_labels(int fd, t_system *sys)
{
  int		i;
  int		j;
  t_conv	conv;

  i = 0;
  while (i < sys->cl)
    {
      j = 0;
      while (j < sys->col)
	{
	  if (strcmp(sys->olabels[j].name, sys->labels[i].name) == 0)
	    {
	      conv.value = sys->labels[i].offset - sys->olabels[j].line;
	      lseek(fd, sys->olabels[j].offset, SEEK_SET);
	      write(fd, &conv.octets[3], 1);
	      write(fd, &conv.octets[2], 1);
	      write(fd, &conv.octets[1], 1);
	      write(fd, &conv.octets[0], 1);
	    }
	  j++;
	}
      i++;
    }
}

void	check_all(t_system *sys, int tmp, char *str, int *values)
{
  if (sys->ins.ret_chck == 0)
    {
      check_instruction(sys);
      sys->ins.c_save = sys->ins.c;
      sys->ins.c = 0;
    }
  if (str[sys->ins.i] == ',')
    sys->ins.cmptr++;
  if ((tmp = register_condition(sys)) != 0)
    values[sys->ins.cmptr] = tmp;
  if ((tmp = direct_condition(sys)) != 0)
    values[sys->ins.cmptr] = tmp;
  if ((tmp = indirect_condition(sys)) != 0)
    values[sys->ins.cmptr] = tmp;
}

int	param_pt(char *str, t_system *sys, t_conv *conv, int *i)
{
  char	tmp[64];
  int	j;

  j = *i + 2;
  memset(tmp, 0, 64);
  while (str[j] != ',' && str[j])
    tmp[(sys->kf)++] = str[j++];
  tmp[sys->kf] = '\0';
  sys->olabels[sys->col].offset = lseek(sys->ins.fd, 0, SEEK_CUR);
  sys->olabels[sys->col].line = sys->start_line;
  sys->olabels[sys->col].name = malloc(strlen(tmp) * sizeof(char));
  strcpy(sys->olabels[sys->col++].name, tmp);
  printf(">> Direct : %s -> %x (4 Octets) (Label Call)\n",
	 tmp, conv->octets[0]);
  dir_data_condition(sys->ins.fd, conv, 1);
  while (str[*i] != ',' && str[*i] != '\0')
    (*i)++;
  return (*i + 2);
}
