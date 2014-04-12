/*
** tread.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:39:27 2014 Jeremy Mediavilla
** Last update Sat Apr 12 20:16:32 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void	tread_line(char *buff, t_system *system, int fd, int line)
{
  int	ret;

  ret = parse_line_cn(buff, system, fd);
  if (ret == 0)
    xwrite_to_file(buff, fd, line, system);
}

void		second_pass(int fd, t_system *sys)
{
  t_conv	conv;
  unsigned int	size;

  size = lseek(fd, 0, SEEK_END) - (4 + 4 + 2048 + 128);
  conv.value = size;
  lseek(fd, 4, SEEK_SET);
  xwrite(fd, &conv.octets[3], 1);
  xwrite(fd, &conv.octets[2], 1);
  xwrite(fd, &conv.octets[1], 1);
  xwrite(fd, &conv.octets[0], 1);
  do_labels(fd, sys);
}

char	*parse_name_file(t_system *sys)
{
  int	i;
  char	*tmp;

  tmp = xmalloc(256 * sizeof(*tmp));
  tmp = my_memset(tmp, '\0', 256);
  i = 0;
  while (sys->name_file[i] != '.' && sys->name_file[i])
    {
      tmp[i] = sys->name_file[i];
      i++;
    }
  my_strcat(tmp, ".cor");
  return (tmp);
}

void		tread_file(char *path, t_system *sys)
{
  int		fd;
  char		*buff;
  int		fd2;
  int		line;
  char		*name;

  buff = xmalloc(4096 * sizeof(*buff));
  my_memset(buff, 0, 4096);
  line = 0;
  name = xmalloc(256 * sizeof(*name));
  name = parse_name_file(sys);
  fd = xopen(path, O_RDONLY);
  fd2 = open(name,
	    O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
  if (fd != -1 && fd2 != -1)
    {
      xwrite_magic(fd2);
      while ((buff = get_next_line(fd)) != NULL)
	{
	  sys->start_line = lseek(fd2, 0, SEEK_CUR);
	  tread_line(buff, sys, fd2, line++);
	}
    }
  second_pass(fd2, sys);
  free(buff);
  free(name);
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
