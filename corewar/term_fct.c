/*
** term_fct.c<2> for term_fct in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 16:01:26 2014 Geoffrey Merran
** Last update Tue Apr  8 16:06:19 2014 Geoffrey Merran
*/

#include "term_fct.h"

void	clear_term()
{
  char	*clear;

  clear = xtgetstr("cl", NULL);
  my_putstr(clear);
}

void	xtgetent(char *bp, char *name)
{
  int	ret;

  ret = tgetent(bp, name);
  if (ret == 0)
    {
      my_puterr("tgetent error : terminal not found\n");
      exit(1);
    }
  if (ret == -1)
    {
      my_puterr("tgetent error : terminal name not valid\n");
      exit(1);
    }
}

char	*xtgetstr(char *id, char **area)
{
  char	*result;

  if ((result = tgetstr(id, area)) == NULL)
    {
      my_puterr("tgetstr error\n");
      exit(1);
    }
  return (result);
}
