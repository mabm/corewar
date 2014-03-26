/*
** parser.h for  in /home/nicolas/Workspace/Corewar/includes
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed Mar 26 11:51:33 2014 Nicolas Ades
** Last update Wed Mar 26 12:06:04 2014 Nicolas Ades
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

struct	s_flags
{
  char *flag;
  void	(*fct)(char *);
};

#endif /* VM_PARSER_H_ */
