/*
** term_fct.h for term_fct in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 16:02:00 2014 Geoffrey Merran
** Last update Tue Apr  8 16:05:15 2014 Geoffrey Merran
*/

#ifndef TERM_FCT_
# define TERM_FCT_
# include <unistd.h>
# include <termios.h>
# include <stdlib.h>
# include <ncurses/curses.h>
# include <term.h>
# include "my.h"
# include "my_printf.h"

char	*xtgetstr(char *id, char **area);
void	xtgetent(char *bp, char *name);
void	clear_term();

#endif /* TERM_FCT_ */
