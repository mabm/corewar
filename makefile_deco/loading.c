/*
** loading.c for Loading in /home/jobertomeu/Work/minitalk/gtk
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 21 23:44:08 2014 Joris Bertomeu
** Last update Wed Apr  2 15:27:33 2014 Geoffrey Merran
*/

#include "../libmy/my.h"

void	homemade_usleep()
{
  int	i;

  i = 0;
  while (i < 2899999)
    i++;
}

int	main()
{
  int	percent;
  int	equals;

  percent = 0;
  equals = 0;
  while (percent <= 100)
    {
      equals = percent / 10;
      my_printf("\r[ %d%% ] [", percent);
      while (equals--)
	my_printf("==");
      equals = percent / 10;
      while (10 - equals++)
	my_putstr("  ");
      my_printf("]");
      percent = percent + 1;
      homemade_usleep();
    }
  my_putchar('\n');
  return (0);
}
