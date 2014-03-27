/*
** main.c for Assembleur in /home/jobertomeu/Work/corewar/assembleur
**
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
**
** Started on  Mon Mar 24 19:52:03 2014 Joris Bertomeu
** Last update Thu Mar 27 17:14:17 2014 Jeremy Mediavilla
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
};

typedef union u_conv t_conv;
union u_conv
{
  char	octets[4];
  int	value;
};

void affbin(unsigned n)
{
  unsigned bit = 0 ;
  unsigned mask = 1 ;
  int	i = 0;

  while (i < 32)
    {
      bit = (n & mask) >> i ;
      printf("%d", bit) ;
      mask <<= 1 ;
      i++;
    }
  printf("\n");
}

void	aff_error(char *msg)
{
  printf(msg);
  exit (0);
}

void	parse_name(char *buff, int k, t_system *system)
{
  int	i;
  int	j;

  j = 0;
  system->name = malloc(strlen(buff) * sizeof(*system->name));
  memset(system->name, 0, strlen(buff));
  i = 2 + k + strlen(".name");
  while (buff[i] != '\"' && buff[i])
    system->name[j++] = buff[i++];
}

void	parse_comment(char *buff, int k, t_system *system)
{
  int	i;
  int	j;

  j = 0;
  system->comment = malloc(strlen(buff) * sizeof(*system->comment));
  memset(system->comment, 0, strlen(buff));
  i = 2 + k + strlen(".comment");
  while (buff[i] != '\"' && buff[i])
    system->comment[j++] = buff[i++];
}

int	parse_line_cn(char *buff, t_system *system)
{
  int	i;
  int	ret;

  ret = 0;
  i = 0;
  while (buff[i])
    {
      if (strncmp(&buff[i], ".comment", strlen(".comment")) == 0)
	{
	  parse_comment(buff, i, system);
	  ret = 1;
	}
      if (strncmp(&buff[i], ".name", strlen(".name")) == 0)
	{
	  parse_name(buff, i, system);
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
  printf("Ecriture des args\n\n");
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
	  printf(">> Registre : %s -> %x (%d)\n", tmp, conv->octets[0], conv->value);
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
	  printf(">> Direct : %s -> %x\n", tmp, conv->octets[0]);
	  if (str[i + 1] != ':')
	    {
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
	  printf(">> Indirect : %s -> %x (%d)\n", tmp, conv->octets[0], conv->value);
	  write(fd, &conv->octets[3], 1);
	  write(fd, &conv->octets[2], 1);
	  write(fd, &conv->octets[1], 1);
	  write(fd, &conv->octets[0], 1);
	}
      i++;
    }
  printf("\n\nFin d'écriture des Args\n\n");
}

void	write_to_file(char *str, int fd)
{
  char	c = 0;
  int	i = 0;
  int	cmptr_param = 0;
  int	ibase;

  while (str[i])
    {
      if (strncmp(&str[i], "sti", 3) == 0)
	{
	  c = 0x0b;
	  write(fd, &c, 1);
	  c = 0;
	  i += 3;
	  ibase = i;
	  if (str[i] == ':')
	    {
	      while (str[i])
		i++;
	    }
	}
      if (strncmp(&str[i], "and", 3) == 0)
	{
	  c = 0x06;
	  write(fd, &c, 1);
	  c = 0;
	  i += 3;
	  ibase = i;
	  if (str[i] == ':')
	    {
	      while (str[i])
		i++;
	    }
	}
      if (strncmp(&str[i], "ld", 2) == 0)
	{
	  c = 0x02;
	  write(fd, &c, 1);
	  c = 0;
	  i += 2;
	  ibase = i;
	  if (str[i] == ':')
	    {
	      while (str[i])
		i++;
	    }
	}
      if (strncmp(&str[i], "live", 4) == 0)
	{
	  c = 0x01;
	  write(fd, &c, 1);
	  c = 0;
	  i += 4;
	  ibase = i;
	  if (str[i] == ':')
	    {
	      while (str[i])
		i++;
	    }
	}
      if (str[i] == ',')
	cmptr_param++;
      if (str[i] == 'r' && '0' <= str[i + 1] &&
	  str[i + 1] <= '9') /* REGISTRE ! */
	{
	  if (cmptr_param == 0)
	    c += 0b01000000;
	  else if (cmptr_param == 1)
	    c += 0b00010000;
	  else if (cmptr_param == 2)
	    c += 0b00000100;
	  else if (cmptr_param == 3)
	    c += 0b00000001;
	  i += 1;
	}
      if (str[i] == '%') /* DIRECT */
	{
	  if (cmptr_param == 0)
	    c += 0b10000000;
	  else if (cmptr_param == 1)
	    c += 0b00100000;
	  else if (cmptr_param == 2)
	    c += 0b00001000;
	  else if (cmptr_param == 3)
	    c += 0b00000010;
	  while (str[i + 1] != ',' && str[i + 1] != '\0')
	    i++;
	}
      if ('0' <= str[i] && str[i] <= '9' && str[i - 1] == ',') /* INDIRECT */
	{
	  if (cmptr_param == 0)
	    c += 0b11000000;
	  else if (cmptr_param == 1)
	    c += 0b00110000;
	  else if (cmptr_param == 2)
	    c += 0b00001100;
	  else if (cmptr_param == 3)
	    c += 0b00000011;
	}
      i++;
    }
  write(fd, &c, 1);
  write_data(ibase, str, fd);
}

void	tread_line(char *buff, t_system *system, int fd)
{
  int	ret;

  ret = parse_line_cn(buff, system);
  if (ret == 0)
    {
      write_to_file(buff, fd);
    }
}

void	tread_file(char *path, t_system *sys)
{
  int	fd;
  char	*buff;
  int	fd2;

  buff = malloc(4096 * sizeof(*buff));
  memset(buff, 0, 4096);
  fd = open(path, O_RDONLY);
  fd2 = open("champ_test.core",
	    O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
  if (fd != -1 && fd2 != -1)
    {
      while ((buff = get_next_line(fd)) != NULL)
	tread_line(buff, sys, fd2);
    }
  free(buff);
}

void	aff_info(t_system *system, char *name)
{
  if (system->name == 0 || system->comment == 0)
    aff_error("One file is corrupt !\n");
  printf("--------------\n\nNom du fichier : %s\n", name);
  printf("Nom du Chamion : %s\n", system->name);
  printf("Commentaire du Champion : %s\n", system->comment);
  printf("\n--------------\n");
}

void	tread_line_cnf_asm(t_system *system, char *buff, int line)
{
  int	i;
  int	j;

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

void	parse_list_asm(t_system *system)
{
  int	fd;
  char	*buff;
  int	line;

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

void	init_cmd_asm(t_system *system)
{
  int	i;
  int	j;

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

void	check_ext(int ac, char **argv)
{
  int	i;

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
  while (i < ac)
    {
      system->comment = 0;
      system->name = 0;
      tread_file(argv[i], system);
      aff_info(system, argv[i++]);
    }
}

int	main(int ac, char *argv[])
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
