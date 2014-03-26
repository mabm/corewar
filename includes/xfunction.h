/*
** xfunction.h for xfunction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Mar 26 13:22:43 2014 Geoffrey Merran
** Last update Wed Mar 26 13:26:14 2014 Geoffrey Merran
*/

#ifndef XFUNCTION_
# define XFUNCTION_
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "my.h"
# include "my_printf.h"

int	xopen(char *pathname, int flags, mode_t mode);

#endif /* XFUNCTION_ */