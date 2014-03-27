/*
** parser.h for  in /home/nicolas/Workspace/Corewar/includes
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed Mar 26 11:51:33 2014 Nicolas Ades
** Last update Thu Mar 27 14:09:08 2014 Nicolas Ades
*/

#ifndef VM_PARSER_H_
# define VM_PARSER_H_

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "vm_corewar.h"

typedef struct	s_info
{
  int		champ_cpt;
  int		ld_add;
  int		prog_nb;
  int		nbr_cycle;
}		t_info;


#endif /* VM_PARSER_H_ */
