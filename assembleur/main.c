/*
** main.c for Assembleur in /home/jobertomeu/Work/corewar/assembleur
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Mon Mar 24 19:52:03 2014 Joris Bertomeu
** Last update Tue Mar 25 13:12:49 2014 Joris Bertomeu
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "gnl.h"

void	tread_file(char *path)
{
  int	fd;
  char	*buff;

  buff = malloc(4096 * sizeof(*buff));
  fd = open(path, O_RDONLY);
  if (fd != -1)
    {
      while ((buff = get_next_line(fd)) != NULL)
	{
	  printf(">> %s\n", buff);
	}
    }
}

void	init(int ac, char **argv)
{
  int	i;

  i = 1;
  while (i < ac)
    tread_file(argv[i]);
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
