/*
** main.c for Assembleur in /home/jobertomeu/Work/corewar/assembleur
**
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
**
** Started on  Mon Mar 24 19:52:03 2014 Joris Bertomeu
** Last update Sat Apr 12 18:37:34 2014 Jeremy Mediavilla
*/

#include "gnl.h"
#include "assembleur.h"

int		get_inst_len(char *str)
{
  int		i;

  i = 0;
  while (str[i] && str[i] != ' ')
    {
      i++;
    }
  return (i);
}

void		create_header(int fd, t_system *sys, int fg)
{
  int		i;
  int		j;
  char		c;

  i = 0;
  c = 0x0;
  if (fg == 1)
    header_init1(&j, sys, fd, &i);
  else
    {
      sys->f_c = 1;
      j = (int) lseek(fd, 0, SEEK_CUR);
      xwrite(fd, sys->comment, my_strlen(sys->comment));
      i = (int) lseek(fd, 0, SEEK_CUR) - j;
      j = 0;
      while (j < COMMENT_LENGTH - i)
	{
	  xwrite(fd, &c, 1);
	  j++;
	}
      my_printf(">> Comment wrote ( %d/%d octets, Total %d octets )\n", i,
	     COMMENT_LENGTH, (int) lseek(fd, 0, SEEK_CUR));
    }
}

void	label_detect(t_system *sys, char *nl)
{
  sys->labels[sys->cl].offset = lseek(sys->ins.fd, 0, SEEK_CUR);
  sys->labels[sys->cl].name = xmalloc(128 * sizeof(char));
  my_strcpy(sys->labels[sys->cl++].name, nl);
  my_printf(">> Label declaration detected : %s | Pos : %d\n", nl,
	 sys->labels[sys->cl - 1].offset);
}

int	point_two(t_system *sys, int i)
{
  sys->ins.i = i + 2;
  return (2);
}

int	main(int ac, char *argv[])
{
  if (ac < 2)
    {
      my_printf("Usage : %s <INPUT_FILE.s>\n", argv[0]);
      return (-1);
    }
  else
    init(ac, argv);
  return (0);
}
