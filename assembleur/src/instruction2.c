/*
** instruction2.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:21:46 2014 Jeremy Mediavilla
** Last update Mon Apr  7 11:27:14 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		and_instruction(t_system *sys)
{
  sys->ins.c = 0x06;
  write(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 3;
  sys->ins.ret_chck = 1;
  printf(">> Instruction : and (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = 0;
      printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}

void		or_instruction(t_system *sys)
{
  sys->ins.c = 0x07;
  write(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 2;
  sys->ins.ret_chck = 0;
  printf(">> Instruction : zjmp (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = 0;
      printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}

void		xor_instruction(t_system *sys)
{
  sys->ins.c = 0x08;
  write(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 3;
  sys->ins.ret_chck = 0;
  printf(">> Instruction : zjmp (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = 0;
      printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}

void		zjmp_instruction(t_system *sys)
{
  sys->ins.c = 0x09;
  write(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 4;
  sys->ins.ret_chck = 0;
  printf(">> Instruction : zjmp (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = 0;
      printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}

void		ldi_instruction(t_system *sys)
{
  sys->ins.c = 0x0a;
  write(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 3;
  sys->ins.ret_chck = 0;
  printf(">> Instruction : zjmp (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = 0;
      printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}
