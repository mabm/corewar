/*
** toto.c for  in /home/mediav_j/corewar/assembleur
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Thu Mar 27 11:54:34 2014 Jeremy Mediavilla
** Last update Thu Mar 27 14:57:18 2014 Jeremy Mediavilla
*/

void		sti_instruction (int fd, char *c, int *i, int *ibase, char *str)
{
  *c = 0x0b;
  write(fd, c, 1);
  *c = 0;
  *i += 3;
  *ibase = *i;
  if (str[*i] == ':')
    {
      printf(">> Label : %s\n", &str[(*i) - 4]);
      while (str[*i])
	(*i)++;
    }
}

void		and_instruction(int fd, char *c, int *i, int *ibase, char *str)
{
  *c = 0x06;
  write(fd, c, 1);
  *c = 0;
  *i += 3;
  *ibase = *i;
  if (str[*i] == ':')
    {
      printf(">> Label : %s\n", &str[(*i) - 4]);
      while (str[*i])
	(*i)++;
    }
}

void		ld_instruction(int fd, char *c, int *i, int *ibase, char *str)
{
  *c = 0x02;
  write(fd, c, 1);
  *c = 0;
  *i += 2;
  *ibase = *i;
  if (str[*i] == ':')
    {
      printf(">> Label : %s\n", &str[(*i) - 4]);
      while (str[*i])
	(*i)++;
    }
}

void		live_instruction(int fd, char *c, int *i, int *ibase, char *str)
{
  *c = 0x01;
  write(fd, c, 1);
  *c = 0;
  *i += 4;
  *ibase = *i;
  if (str[*i] == ':')
    {
      printf(">> Label : %s\n", &str[(*i) - 4]);
      while (str[*i])
	(*i)++;
    }
}

int		check_instruction(char *str, char *c, int *i, int *ibase, int fd)
{
  char		*tab[4];
  void		(*which_instruction[4])(int fd, char *c, int *i, int *ibase, char *str);
  int		j;

  tab[0] = "sti";
  tab[1] = "and";
  tab[2] = "ld";
  tab[3] = "live";
  which_instruction[0] = &sti_instruction;
  which_instruction[1] = &and_instruction;
  which_instruction[2] = &ld_instruction;
  which_instruction[3] = &live_instruction;
  j = 0;
  while (j < 4)
    {
      if (strncmp(&str[*i], tab[j], strlen(tab[j])) == 0)
	{
	  (*which_instruction[j])(fd, c, i, ibase, str);
	  j = 5;
	}
      j++;
    }
  if (j == 4)
    return (0);
}

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
