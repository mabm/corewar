/*
** parser.h for  in /home/nicolas/Workspace/Corewar/includes
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed Mar 26 11:51:33 2014 Nicolas Ades
** Last update Sat Mar 29 20:12:35 2014 Geoffrey Merran
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
# include "my.h"
# include "xfunction.h"
# include "vm_corewar.h"
# include "vm_getchamp.h"

void	vm_pars(int ac, char **av, t_cycles *cycles, t_champ **champs);

#endif /* VM_PARSER_H_ */
