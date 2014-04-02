/*
** instruction2.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:21:46 2014 Jeremy Mediavilla
** Last update Wed Apr  2 15:22:37 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		and_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x06;
  write(fd, c, 1);
  *c = 0;
  *i += 3;
  *ret_chck = 1;
  printf(">> Instruction : and (1 Octet)\n");
  if (str[*i] == ':')
    {
      *ret_chck = 0;
      printf(">> Label : %s\n", &str[(*i) - 4]);
      while (str[*i] && str[*i] != '%')
  	(*i)++;
    }
  *ibase = *i;
}

void		or_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x07;
  write(fd, c, 1);
  *c = 0;
  *i += 2;
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

void		xor_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x08;
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

void		zjmp_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x09;
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

void		ldi_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x0a;
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
