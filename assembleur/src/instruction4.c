/*
** instruction4.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:27:16 2014 Jeremy Mediavilla
** Last update Thu Apr  3 14:58:59 2014 Joris Bertomeu
*/

#include "assembleur.h"
#include "gnl.h"

void		aff_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x10;
  write(fd, c, 1);
  *c = 0;
  *i += 3;
  *ret_chck = 0;
  printf(">> Instruction : zjmp (1 Octet)\n");
  if (str[*i] == ':')
    {
      *ret_chck = 0;
      printf(">> Label : %s\n", &str[(*i) - 4]);
      
      while (str[*i] && str[*i] != '%')
  	(*i)++;
    }
  *ibase = *i;
}
