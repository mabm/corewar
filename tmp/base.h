/*
** base.h for  in /home/mediav_j/corewar/tmp
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Mar 26 17:15:09 2014 Jeremy Mediavilla
** Last update Thu Mar 27 11:14:06 2014 Jeremy Mediavilla
*/

#ifndef BASE_H
# define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define	BIN	"01"
# define	DEC	"0123456789"
# define	HEX	"0123456789ABCDEF"

int		my_getnbr_base(char *, char *);
int		my_strlen(char *);
char		*convert_base_str(char *, char *, char *);
char		*convert_base_int(int, char *);
int		my_strcmp(char *, char *);

#endif /* BASE_H */
