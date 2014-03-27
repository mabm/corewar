/*
** toto.c for  in /home/mediav_j/corewar/assembleur
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Thu Mar 27 11:54:34 2014 Jeremy Mediavilla
** Last update Thu Mar 27 17:17:38 2014 Jeremy Mediavilla
*/

int		write_to_file(char *str, int fd)
{
  char		c;
  int		i;
  int		cmptr_param;
  int		ibase;

  i = 0;
  c = 0;
  cmptr_param = 0;
  while (str[i])
    {
      check_instruction(str, &c, &i, &ibase, fd);
      if (str[i] == ',')
	cmptr_param++;
      if (str[i] == 'r' && '0' <= str[i + 1] &&
	  str[i + 1] <= '9') /* REGISTRE ! */
	{
	  if (cmptr_param == 0)
	    c += 0b01000000;
	  else if (cmptr_param == 1)
	    c += 0b00010000;
	  else if (cmptr_param == 2)
	    c += 0b00000100;
	  else if (cmptr_param == 3)
	    c += 0b00000001;
	  i += 1;
	}
      if (str[i] == '%') /* DIRECT */
	{
	  if (cmptr_param == 0)
	    c += 0b10000000;
	  else if (cmptr_param == 1)
	    c += 0b00100000;
	  else if (cmptr_param == 2)
	    c += 0b00001000;
	  else if (cmptr_param == 3)
	    c += 0b00000010;
	  while (str[i + 1] != ',' && str[i + 1] != '\0')
	    i++;
	}
      if ('0' <= str[i] && str[i] <= '9' && str[i - 1] == ',') /* INDIRECT */
	{
	  if (cmptr_param == 0)
	    c += 0b11000000;
	  else if (cmptr_param == 1)
	    c += 0b00110000;
	  else if (cmptr_param == 2)
	    c += 0b00001100;
	  else if (cmptr_param == 3)
	    c += 0b00000011;
	}
      i++;
    }
  write(fd, &c, 1);
  write_data(ibase, str, fd);
}
