/*
** instruction3.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:23:20 2014 Jeremy Mediavilla
** Last update Wed Apr  9 14:04:15 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		sti_instruction (t_system *sys)
{
  sys->ins.c = 0x0b;
  write(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 3;
  sys->ins.ret_chck = 1;
  my_printf(">> Instruction : sti (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = -1;
      my_printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}

void		fork_instruction(t_system *sys)
{
  sys->ins.c = 0x0c;
  write(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 4;
  sys->ins.ret_chck = 1;
  my_printf(">> Instruction : fork (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = -1;
      my_printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}

void		lfork_instruction(t_system *sys)
{
  sys->ins.c = 0x0f;
  write(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 5;
  sys->ins.ret_chck = 1;
  my_printf(">> Instruction : lfork (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = -1;
      my_printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}

void		lld_instruction(t_system *sys)
{
  sys->ins.c = 0x0d;
  write(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 3;
  sys->ins.ret_chck = 1;
  my_printf(">> Instruction : lld (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = -1;
      my_printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}

void		lldi_instruction(t_system *sys)
{
  sys->ins.c = 0x0e;
  write(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 4;
  sys->ins.ret_chck = 1;
  my_printf(">> Instruction : lldi (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = -1;
      my_printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}
