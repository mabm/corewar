/*
** tread.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:39:27 2014 Jeremy Mediavilla
** Last update Tue Apr  8 23:36:58 2014 Joris Bertomeu
*/

#include "assembleur.h"
#include "gnl.h"

void		tread_line(char *buff, t_system *system, int fd, int line)
{
  int		ret;

  ret = parse_line_cn(buff, system, fd);
  if (ret == 0)
    write_to_file(buff, fd, line);
}

void	second_pass(int fd, t_system *sys)
{
  t_conv	conv;
  unsigned int	size;

  size = lseek(fd, 0, SEEK_END) - (4 + 4 + 2048 + 128);
  conv.value = size;
  lseek(fd, 4, SEEK_SET);
  write(fd, &conv.octets[3], 1);
  write(fd, &conv.octets[2], 1);
  write(fd, &conv.octets[1], 1);
  write(fd, &conv.octets[0], 1);
}

void		tread_file(char *path, t_system *sys)
{
  int		fd;
  char		*buff;
  int		fd2;
  int		line;

  buff = malloc(4096 * sizeof(*buff));
  memset(buff, 0, 4096);
  line = 0;
  fd = open(path, O_RDONLY);
  fd2 = open("champion.cor",
	    O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
  if (fd != -1 && fd2 != -1)
    {
      write_magic(fd2);
      while ((buff = get_next_line(fd)) != NULL)
	tread_line(buff, sys, fd2, line++);
    }
  second_pass(fd2, sys);
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
