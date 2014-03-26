/*
** main.c for Assembleur in /home/jobertomeu/Work/corewar/assembleur
**
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
**
** Started on  Mon Mar 24 19:52:03 2014 Joris Bertomeu
** Last update Wed Mar 26 11:13:28 2014 Joris Bertomeu
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "gnl.h"

typedef struct s_system t_system;
struct s_system
{
  int	comment;
  char	***cmd_asm;
  char	*name;
};

void	parse_name(char *buff, int k, t_system *system)
{
  int	i;
  int	j;

  j = 0;
  i = 2 + k + strlen(".comment");
  system->name = malloc(strlen(buff) * sizeof(*system->name));
  while (buff[i] != '\"' && buff[i])
    system->name[j++] = buff[i++];
}

void	parse_line_comment(char *buff, t_system *system)
{
  int	i;

  i = 0;
  while (buff[i])
    {
      if (strncmp(&buff[i], ".comment", strlen(".comment")) == 0)
	parse_name(buff, i, system);
      if (strncmp(&buff[i], ".name", strlen(".name")) == 0)
	printf("Nom : %s\n", &buff[1 + i + strlen(".name")]);
      i++;
    }
}

void	tread_line(char *buff, t_system *system)
{
  parse_line_comment(buff, system);
}

void	tread_file(char *path, t_system *system)
{
  int	fd;
  char	*buff;

  buff = malloc(4096 * sizeof(*buff));
  fd = open(path, O_RDONLY);
  if (fd != -1)
    {
      while ((buff = get_next_line(fd)) != NULL)
	tread_line(buff, system);
    }
  free(buff);
}

void	aff_info(t_system *system, char *name)
{
  printf("--------------\n\nNom du fichier : %s\n", name);
  printf("Nom du Chamion : %s\n", system->name);
  printf("\n--------------\n");
}

void	tread_line_cnf_asm(t_system *system, char *buff, int line)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (buff[i] != ':')
    system->cmd_asm[line][0][i] = buff[i++];
  i++;
  while (buff[i] != '\0')
    system->cmd_asm[line][1][j++] = buff[i++];
  printf("%s = %s\n", system->cmd_asm[line][0],
	 system->cmd_asm[line][1]);
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
  free(buff);
}

void	init_cmd_asm(t_system *system)
{
  int	i;
  int	j;

  i = 0;
  system->cmd_asm = malloc(16 * sizeof(*system->cmd_asm));
  while (i < 16)
    {
      system->cmd_asm[i] = malloc(2 * sizeof(**system->cmd_asm));
      j = 0;
      while (j < 2)
	system->cmd_asm[i][j++] = malloc(32 * sizeof(***system->cmd_asm));
      i++;
    }
  parse_list_asm(system);
}

void		init(int ac, char **argv)
{
  int		i;
  t_system	*system;

  i = 1;
  system = malloc(sizeof(*system));
  init_cmd_asm(system);
  while (i < ac)
    {
      system->comment = 0;
      tread_file(argv[i], system);
      aff_info(system, argv[i++]);
    }
}

int	main(int ac, char *argv[])
{
  if (ac < 2)
    {
      printf("Usage : %s <INPUT_FILE>\n", argv[0]);
      return (-1);
    }
  else
    init(ac, argv);
  return (0);
}
