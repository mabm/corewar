/*
** main.c for Assembleur in /home/jobertomeu/Work/corewar/assembleur
**
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
**
** Started on  Mon Mar 24 19:52:03 2014 Joris Bertomeu
** Last update Wed Apr  9 22:38:09 2014 Joris Bertomeu
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
      write(fd, sys->comment, strlen(sys->comment));
      i = (int) lseek(fd, 0, SEEK_CUR) - j;
      j = 0;
      while (j < COMMENT_LENGTH - i)
	{
	  write(fd, &c, 1);
	  j++;
	}
      printf(">> Comment wrote ( %d/%d octets, Total %d octets )\n", i,
	     COMMENT_LENGTH, (int) lseek(fd, 0, SEEK_CUR));
    }
}

void	new_label(t_system *sys)
{
  int	i;
  char	*nl;
  int	flag;

  i = 0;
  flag = 0;
  nl = malloc(128 * sizeof(char));
  while (sys->ins.str[i] != ':' && sys->ins.str[i] != ' ' && sys->ins.str[i])
    {
      nl[i] = sys->ins.str[i];
      i++;
    }
  if (sys->ins.str[i] == ':')
    {
      sys->ins.i = i + 2;
      flag = 2;
    }
  nl[i] = '\0';
  i = 0;
  while (i < sys->cl)
    {
      if (strcmp(sys->labels[i].name, nl) == 0)
	flag = 1;
      i++;
    }
  if (flag == 2)
    {
      sys->labels[sys->cl].offset = lseek(sys->ins.fd, 0, SEEK_CUR);
      sys->labels[sys->cl].name = malloc(128 * sizeof(char));
      strcpy(sys->labels[sys->cl++].name, nl);
      printf(">> Label declaration detected : %s | Pos : %d\n", nl,
	     sys->labels[sys->cl - 1].offset);
    }
}

int		check_instruction(t_system *sys)
{
  char		**tab;
  void		(*which_instruction[16])(t_system *sys);
  int		j;
  int		flag;

  flag = 0;
  tab = init_tab();
  which_instruction[0] = &sti_instruction;
  which_instruction[1] = &and_instruction;
  which_instruction[2] = &ld_instruction;
  which_instruction[3] = &live_instruction;
  which_instruction[4] = &zjmp_instruction;
  which_instruction[5] = &st_instruction;
  which_instruction[6] = &add_instruction;
  which_instruction[7] = &sub_instruction;
  which_instruction[8] = &or_instruction;
  which_instruction[9] = &xor_instruction;
  which_instruction[10] = &ldi_instruction;
  which_instruction[11] = &fork_instruction;
  which_instruction[12] = &lld_instruction;
  which_instruction[13] = &lldi_instruction;
  which_instruction[14] = &lfork_instruction;
  which_instruction[15] = &aff_instruction;
  new_label(sys);
  j = 0;
  while (j < 16)
    {
      if (strncmp(&sys->ins.str[sys->ins.i], tab[j],
		  get_inst_len(&sys->ins.str[sys->ins.i])) == 0)
	{
	  (*which_instruction[j])(sys);
	  j = 16;
	}
      j++;
    }
  return (sys->ins.ret_chck);
}

void		check_ext(int ac, char **argv)
{
  int		i;

  i = 1;
  while (i < ac)
    {
      if (strncmp(&argv[i][strlen(argv[i]) - 2], ".s", 2) != 0)
	aff_error("*.s Only !\n");
      i++;
    }
}

int		main(int ac, char *argv[])
{
  if (ac < 2)
    {
      printf("Usage : %s <INPUT_FILE.s>\n", argv[0]);
      return (-1);
    }
  else
    init(ac, argv);
  return (0);
}
