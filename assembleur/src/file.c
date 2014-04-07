/*
** file.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:33:49 2014 Jeremy Mediavilla
** Last update Mon Apr  7 16:01:40 2014 Joris Bertomeu
*/

#include "assembleur.h"
#include "gnl.h"

void		register_condition(t_system *sys)
{
  if (sys->ins.str[sys->ins.i] == 'r' && '0' <= sys->ins.str[sys->ins.i + 1] &&
      sys->ins.str[sys->ins.i + 1] <= '9')
    {
      if (sys->ins.cmptr == 0)
	sys->ins.c += 0x40;
      else if (sys->ins.cmptr == 1)
	sys->ins.c += 0x10;
      else if (sys->ins.cmptr == 2)
	sys->ins.c += 0x4;
      else if (sys->ins.cmptr == 3)
	sys->ins.c += 0x1;
      sys->ins.i += 1;
    }
}

void		direct_condition(t_system *sys)
{
  if (sys->ins.str[sys->ins.i] == '%')
    {
      if (sys->ins.cmptr == 0)
	sys->ins.c += 0x80;
      else if (sys->ins.cmptr == 1)
	sys->ins.c += 0x20;
      else if (sys->ins.cmptr == 2)
	sys->ins.c += 0x8;
      else if (sys->ins.cmptr == 3)
	sys->ins.c += 0x2;
      while (sys->ins.str[sys->ins.i + 1] != ',' &&
	     sys->ins.str[sys->ins.i + 1] != '\0')
	(sys->ins.i)++;
    }
}

void		indirect_condition(t_system *sys)
{
  if ('0' <= sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] <= '9' &&
      sys->ins.str[sys->ins.i - 1] == ',')
    {
      if (sys->ins.cmptr == 0)
	sys->ins.c += 0xC0;
      else if (sys->ins.cmptr == 1)
	sys->ins.c += 0x30;
      else if (sys->ins.cmptr == 2)
	sys->ins.c += 0xC;
      else if (sys->ins.cmptr == 3)
	sys->ins.c += 0x3;
    }
}

void		write_to_file(char *str, int fd)
{
  t_system	sys;

  sys.ins.fd = fd;
  sys.ins.str = str;
  sys.ins.c = 0;
  sys.ins.i = 0;
  sys.ins.ibase = 0;
  sys.ins.ret_chck = 0;
  sys.ins.cmptr = 0;
  while (str[sys.ins.i])
    {
      if (sys.ins.ret_chck == 0)
	{
	  sys.ins.ret_chck = check_instruction(&sys);
	  sys.ins.c = 0;
	}
      if (str[sys.ins.i] == ',')
	sys.ins.cmptr++;
      register_condition(&sys);
      direct_condition(&sys);
      indirect_condition(&sys);
      sys.ins.i++;
    }
  if (sys.ins.ret_chck == 1)
    write(fd, &sys.ins.c, 1);
  write_data(sys.ins.ibase, str, fd);
}
