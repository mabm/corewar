/*
** pars.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:11:09 2014 Jeremy Mediavilla
** Last update Wed Apr  2 15:12:30 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

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
