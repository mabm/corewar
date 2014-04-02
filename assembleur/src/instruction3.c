/*
** instruction3.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:23:20 2014 Jeremy Mediavilla
** Last update Wed Apr  2 15:25:56 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		sti_instruction (int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x0b;
  write(fd, c, 1);
  *c = 0;
  *i += 3;
  *ret_chck = 1;
  printf(">> Instruction : sti (1 Octet)\n");
  if (str[*i] == ':')
    {
      *ret_chck = 0;
      printf(">> Label : %s\n", &str[(*i) - 4]);
      while (str[*i] && str[*i] != '%')
  	(*i)++;
    }
  *ibase = *i;
}

void		fork_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x0c;
  write(fd, c, 1);
  *c = 0;
  *i += 4;
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

void		lfork_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x0f;
  write(fd, c, 1);
  *c = 0;
  *i += 5;
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

void		lld_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x0d;
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

void		lldi_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x0e;
  write(fd, c, 1);
  *c = 0;
  *i += 4;
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
