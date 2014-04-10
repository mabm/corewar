/*
** vm_getparams.c for vm_getparams in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Apr 10 01:13:59 2014 Geoffrey Merran
** Last update Thu Apr 10 02:51:22 2014 Geoffrey Merran
*/

#include "vm_getparams.h"

void	get_codage(unsigned char code, char **params, int nb_args)
{
  int	i;
  int	j;

  i = 0;
  while (i < nb_args)
    {
      j = 0;
      params[TYPE_P][i] = 0;
      while (j < 2)
	{
	  if ((code & 128) != 0)
	    params[TYPE_P][i] += my_power_rec(2, (1 - j));
	  code = code << 1;
	  j++;
	}
      i++;
    }
}

char	**get_params(int nb_args, t_arena *arena, int address)
{
  char	**params;
  int	i;

  i = 0;
  params = my_xmalloc(2 * sizeof(char *));
  params[TYPE_P] = my_xmalloc(nb_args * sizeof(char));
  params[VALUE_P] = my_xmalloc(nb_args * sizeof(char));
  get_codage(arena->arena[address], params, nb_args);
  /* commentaire pour moi du lendemain :

     - t'as recuperer dans params[0] : les types de paramatres
     - il faut que tu modifies le malloc pour malloc d'autant de nb_args en +
     - dans params[+ que 0] tu stock les valeurs des parametres

     - du coup le but c'est que tu renvoies un char ** qui permet de :

     params[0][0] = Type premier parametre
     params[1][...] = valeurs sur 1 à 4 octet (4 char)

     params[0][1] = Type deuxieme parametre
     params[2][...] = valeurs sur 1 à 4 octet (4 char)

     ...

     Bonne chance moi du futur !
		- moi du passé
   */
  printf("nbr arg : %d\n", nb_args);
  while (i < nb_args)
    printf("value : %d\n", params[TYPE_P][i++]);
  return (params);
}
