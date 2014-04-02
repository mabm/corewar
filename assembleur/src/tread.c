/*
** tread.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:39:27 2014 Jeremy Mediavilla
** Last update Wed Apr  2 15:39:55 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		tread_line(char *buff, t_system *system, int fd)
{
  int		ret;

  ret = parse_line_cn(buff, system, fd);
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
      write_magic(fd2);
      while ((buff = get_next_line(fd)) != NULL)
	tread_line(buff, sys, fd2);
    }
  free(buff);
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
