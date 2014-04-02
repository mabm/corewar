/*
** instruction1.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:18:04 2014 Jeremy Mediavilla
** Last update Wed Apr  2 15:20:05 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		live_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x01;
  write(fd, c, 1);
  *c = 0;
  *i += 4;
  *ret_chck = 1;
  printf(">> Instruction : live (1 Octet)\n");
  if (str[*i] == ':')
    {
      *ret_chck = 0;
      printf(">> Label @%d: %s\n", (int) lseek(fd, 0, SEEK_CUR),
	     &str[(*i) - 4]);
      while (str[*i] && str[*i] != '%')
  	(*i)++;
    }
  *ibase = *i;
}

void		ld_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x02;
  write(fd, c, 1);
  *c = 0;
  *i += 2;
  *ret_chck = 1;
  printf(">> Instruction : ld (1 Octet)\n");
  if (str[*i] == ':')
    {
      *ret_chck = 0;
      printf(">> Label : %s\n", &str[(*i) - 4]);
      while (str[*i] && str[*i] != '%')
  	(*i)++;
    }
  *ibase = *i;
}

void		st_instruction (int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x03;
  write(fd, c, 1);
  *c = 0;
  *i += 2;
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

void		add_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x04;
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

void		sub_instruction(int fd, char *c, int *i, int *ibase, char *str, int *ret_chck)
{
  *c = 0x05;
  write(fd, c, 1);
  *c = 0;
  *i += 3;
  *ret_chck = 1;
  printf(">> Instruction : ld (1 Octet)\n");
  if (str[*i] == ':')
    {
      *ret_chck = 0;
      printf(">> Label : %s\n", &str[(*i) - 4]);
      while (str[*i] && str[*i] != '%')
  	(*i)++;
    }
  *ibase = *i;
}
