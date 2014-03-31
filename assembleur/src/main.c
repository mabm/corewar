/*
** main.c for Assembleur in /home/jobertomeu/Work/corewar/assembleur
**
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
**
** Started on  Mon Mar 24 19:52:03 2014 Joris Bertomeu
** Last update Mon Mar 31 10:43:47 2014 Jeremy Mediavilla
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <byteswap.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "gnl.h"

typedef struct s_system t_system;
struct s_system
{
  char	***cmd_asm;
  char	*name;
  char	*comment;
  int	nb_comment;
  int	nb_name;
  int	f_c;
  int	f_n;
  int	wm;
};

typedef union u_conv t_conv;
union u_conv
{
  char	octets[4];
  int	value;
};

void		affbin(unsigned n)
{
  unsigned	bit;
  unsigned	mask;
  int		i;

  bit = 0;
  i = 0;
  mask = 1;
  while (i < 32)
    {
      bit = (n & mask) >> i;
      printf("%d", bit) ;
      mask <<= 1 ;
      i++;
    }
  printf("\n");
}

void		aff_error(char *msg)
{
  printf(msg);
  exit (0);
}

void		parse_name(char *buff, int k, t_system *system)
{
  int		i;
  int		j;

  j = 0;
  if (strlen(buff) >= 199)
    aff_error("Name >= 199, name must be shorter\n");
  system->name = malloc(strlen(buff) * sizeof(*system->name));
  memset(system->name, 0, strlen(buff));
  i = 2 + k + strlen(".name");
  while (buff[i] != '\"' && buff[i])
    system->name[j++] = buff[i++];
}

void		parse_comment(char *buff, int k, t_system *system)
{
  int		i;
  int		j;

  j = 0;
  if (strlen(buff) >= 199)
    aff_error("Comment >= 199, comment must be shorter\n");
  system->comment = malloc(strlen(buff) * sizeof(*system->comment));
  memset(system->comment, 0, strlen(buff));
  i = 2 + k + strlen(".comment");
  while (buff[i] != '\"' && buff[i])
    system->comment[j++] = buff[i++];
}

void		header_init1(int *j, t_system *sys, int fd, int *i)
{
  char		c;

  c = 0x0;
  sys->f_n = 1;
  *j = (int) lseek(fd, 0, SEEK_CUR);
  write(fd, "name:", 5);
  write(fd, sys->name, strlen(sys->name));
  *i = (int) lseek(fd, 0, SEEK_CUR) - *j;
  *j = 0;
  while (*j < 200 - *i)
    {
      write(fd, &c, 1);
      (*j)++;
    }
  printf(">> Comment wrote ( %d/200 octets, Total %d octets )\n", *i,
	 (int) lseek(fd, 0, SEEK_CUR));
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
      write(fd, "comment:", 8);
      write(fd, sys->comment, strlen(sys->comment));
      i = (int) lseek(fd, 0, SEEK_CUR) - j;
      j = 0;
      while (j < 200 - i)
	{
	  write(fd, &c, 1);
	  j++;
	}
      printf(">> Comment wrote ( %d/200 octets, Total %d octets )\n", i,
	     (int) lseek(fd, 0, SEEK_CUR));
    }
}

int		parse_line_cn(char *buff, t_system *system, int fd)
{
  int		i;
  int		ret;

  ret = 0;
  i = 0;
  while (buff[i])
    {
      if (strncmp(&buff[i], ".comment", strlen(".comment")) == 0)
	{
	  parse_comment(buff, i, system);
	  create_header(fd, system, 2);
	  ret = 1;
	}
      if (strncmp(&buff[i], ".name", strlen(".name")) == 0)
	{
	  parse_name(buff, i, system);
	  create_header(fd, system, 1);
	  ret = 1;
	}
	i++;
    }
  return (ret);
}

void		write_data(int ibase, char *str, int fd)
{
  int		i;
  int		j;
  char		tmp[64];
  int		k;
  t_conv	*conv;

  conv = malloc(sizeof(*conv));
  i = ibase;
  while (str[i])
    {
      if (str[i] == 'r' && '0' <= str[i + 1] &&
	  str[i + 1] <= '9') /* REGISTRE ! */
	{
	  j = i;
	  k = 0;
	  memset(tmp, 0, 64);
	  while (str[j] != ',' && str[j])
	    tmp[k++] = str[j++];
	  conv->value = atoi(&tmp[1]);
	  printf(">> Registre : %s -> %x (%d) (1 Octet)\n", tmp,
		 conv->octets[0], conv->value);
	  write(fd, &conv->octets[0], 1);
	  i += 1;
	}
      if (str[i] == '%') /* DIRECT */
	{
	  j = i;
	  k = 0;
	  memset(tmp, 0, 64);
	  while (str[j] != ',' && str[j])
	    tmp[k++] = str[j++];
	  conv->value = atoi(&tmp[1]);
	  printf(">> Direct : %s -> %x (4 Octets)\n", tmp, conv->octets[0]);
	  if (str[i + 1] != ':')
	    {
	      write(fd, &conv->octets[3], 1);
	      write(fd, &conv->octets[2], 1);
	      write(fd, &conv->octets[1], 1);
	      write(fd, &conv->octets[0], 1);
	    }
	  else
	    {
	      conv->value = 0;
	      write(fd, &conv->octets[3], 1);
	      write(fd, &conv->octets[2], 1);
	      write(fd, &conv->octets[1], 1);
	      write(fd, &conv->octets[0], 1);
	    }
	  while (str[i + 1] != ',' && str[i + 1] != '\0')
	    i++;
	}
      if ('0' <= str[i] && str[i] <= '9' && str[i - 1] == ',') /* INDIRECT */
	{
	  j = i;
	  k = 0;
	  memset(tmp, 0, 64);
	  while (str[j] != ',' && str[j] && '0' <= str[j] && str[j] <= '9')
	    tmp[k++] = str[j++];
	  conv->value = atoi(&tmp[1]);
	  printf(">> Indirect : %s -> %x (%d) (4 Octets)\n", tmp,
		 conv->octets[0], conv->value);
	  write(fd, &conv->octets[3], 1);
	  write(fd, &conv->octets[2], 1);
	  write(fd, &conv->octets[1], 1);
	  write(fd, &conv->octets[0], 1);
	}
      if (str[i] != '\0')
	i++;
    }
  printf("\n>>------ Next line ------<<\n");
}

void		sti_instruction (int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x0b;
  write(fd, c, 1);
  *c = 0;
  *i += 3;
  *ret_chck = 1;
  printf(">> Instruction : sti (1 Octet)\n");
  if (str[*i] == ':')
    {
      *ret_chck = 0;
      printf(">> Label : %s\n", &str[(*i) - 4]);
      while (str[*i] && str[*i] != '%')
  	(*i)++;
    }
  *ibase = *i;
}

void		and_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x06;
  write(fd, c, 1);
  *c = 0;
  *i += 3;
  *ret_chck = 1;
  printf(">> Instruction : and (1 Octet)\n");
  if (str[*i] == ':')
    {
      *ret_chck = 0;
      printf(">> Label : %s\n", &str[(*i) - 4]);
      while (str[*i] && str[*i] != '%')
  	(*i)++;
    }
  *ibase = *i;
}

void		ld_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x02;
  write(fd, c, 1);
  *c = 0;
  *i += 2;
  *ret_chck = 1;
  printf(">> Instruction : ld (1 Octet)\n");
  if (str[*i] == ':')
    {
      *ret_chck = 0;
      printf(">> Label : %s\n", &str[(*i) - 4]);
      while (str[*i] && str[*i] != '%')
  	(*i)++;
    }
  *ibase = *i;
}

void		live_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x01;
  write(fd, c, 1);
  *c = 0;
  *i += 4;
  *ret_chck = 1;
  printf(">> Instruction : live (1 Octet)\n");
  if (str[*i] == ':')
    {
      *ret_chck = 0;
      printf(">> Label @%d: %s\n", (int) lseek(fd, 0, SEEK_CUR),
	     &str[(*i) - 4]);
      while (str[*i] && str[*i] != '%')
  	(*i)++;
    }
  *ibase = *i;
}

void		zjmp_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x09;
  write(fd, c, 1);
  *c = 0;
  *i += 4;
  *ret_chck = 0;
  printf(">> Instruction : zjmp (1 Octet)\n");
  if (str[*i] == ':')
    {
      *ret_chck = 0;
      printf(">> Label : %s\n", &str[(*i) - 4]);
      while (str[*i] && str[*i] != '%')
  	(*i)++;
    }
  *ibase = *i;
}

int		check_instruction(char *str, char *c, int *i, int *ibase, int fd)
{
  char		*tab[5];
  void		(*which_instruction[5])(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck);
  int		j;
  int		ret_chck;

  tab[0] = "sti";
  tab[1] = "and";
  tab[2] = "ld";
  tab[3] = "live";
  tab[4] = "zjmp";
  ret_chck = 0;
  which_instruction[0] = &sti_instruction;
  which_instruction[1] = &and_instruction;
  which_instruction[2] = &ld_instruction;
  which_instruction[3] = &live_instruction;
  which_instruction[4] = &zjmp_instruction;
  j = 0;
  while (j < 5)
    {
      if (strncmp(&str[*i], tab[j], strlen(tab[j])) == 0)
	{
	  (*which_instruction[j])(fd, c, i, ibase, str, &ret_chck);
	  j = 5;
	}
      j++;
    }
  return (ret_chck);
}

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

void	write_magic(int fd, t_system *sys)
{
  char	c[4];

  c[0] = 'm';
  c[1] = 'a';
  c[2] = 'b';
  c[3] = 'm';
  sys->wm = 1;
  write(fd, &c, 4);
  printf(">> Passphrase Wrote : **** ( 4 Octets )\n\n");
}

void		tread_line(char *buff, t_system *system, int fd)
{
  int		ret;

  ret = parse_line_cn(buff, system, fd);
  if (system->f_c == 1 && system->f_n == 1 && system->wm == 0)
    write_magic(fd, system);
  if (ret == 0)
    write_to_file(buff, fd);
}

void		tread_file(char *path, t_system *sys)
{
  int		fd;
  char		*buff;
  int		fd2;

  buff = malloc(4096 * sizeof(*buff));
  memset(buff, 0, 4096);
  fd = open(path, O_RDONLY);
  fd2 = open("champion.cor",
	    O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
  if (fd != -1 && fd2 != -1)
    {
      while ((buff = get_next_line(fd)) != NULL)
	tread_line(buff, sys, fd2);
    }
  free(buff);
}

void		aff_info(t_system *system, char *name)
{
  if (system->name == 0 || system->comment == 0)
    aff_error("One file is corrupt !\n");
  printf("--------------\n\nNom du fichier : %s\n", name);
  printf("Nom du Chamion : %s\n", system->name);
  printf("Commentaire du Champion : %s\n", system->comment);
  printf("\n--------------\n");
}

void		tread_line_cnf_asm(t_system *system, char *buff, int line)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (buff[i] != ':')
    {
      system->cmd_asm[line][0][i] = buff[i];
      i++;
    }
  i++;
  while (buff[i] != '\0')
    {
      system->cmd_asm[line][1][j++] = buff[i];
      i++;
    }
}

void		parse_list_asm(t_system *system)
{
  int		fd;
  char		*buff;
  int		line;

  line = 0;
  buff = malloc(4096 * sizeof(*buff));
  fd = open("asm.cnf", O_RDONLY);
  if (fd != -1)
    {
      while ((buff = get_next_line(fd)) != NULL)
	tread_line_cnf_asm(system, buff, line++);
    }
  close(fd);
  free(buff);
}

void		init_cmd_asm(t_system *system)
{
  int		i;
  int		j;

  i = 0;
  system->cmd_asm = malloc(16 * sizeof(*system->cmd_asm));
  memset(system->cmd_asm, 0, 16 * sizeof(*system->cmd_asm) - 1);
  while (i < 16)
    {
      system->cmd_asm[i] = malloc(2 * sizeof(**system->cmd_asm));
      memset(system->cmd_asm[i], 0, 2 * sizeof(**system->cmd_asm) - 1);
      j = 0;
      while (j < 2)
	{
	  system->cmd_asm[i][j] = malloc(32 * sizeof(***system->cmd_asm));
	  memset(system->cmd_asm[i][j++], 0, 32 * sizeof(***system->cmd_asm) - 1);
	}
      i++;
    }
  parse_list_asm(system);
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

void		init(int ac, char **argv)
{
  int		i;
  t_system	*system;

  i = 1;
  system = malloc(sizeof(*system));
  check_ext(ac, argv);
  system->f_c = 0;
  system->f_n = 0;
  system->wm = 0;
  while (i < ac)
    {
      system->comment = 0;
      system->name = 0;
      tread_file(argv[i], system);
      aff_info(system, argv[i++]);
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
