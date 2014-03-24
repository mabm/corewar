/*
** main.c for Assembleur in /home/jobertomeu/Work/corewar/assembleur
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Mon Mar 24 19:52:03 2014 Joris Bertomeu
** Last update Mon Mar 24 19:57:18 2014 Joris Bertomeu
*/

void	init(int ac, char **argv)
{
  int	i;

  i = 1;
  while (i < ac)
    printf("Initialisation de %s\n", argv[i++]);
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
