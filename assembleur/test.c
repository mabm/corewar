#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void affbin(unsigned n)
{
  unsigned bit = 0 ;
  unsigned mask = 1 ;
  int	i = 0;

  while (i < 32)
    {
      bit = (n & mask) >> i ;
      printf("%d", bit) ;
      mask <<= 1 ;
      i++;
    }
}

int	write_to_file(char *str)
{
  int	fd;
  char	c;
  // char	*str = "sti r1,\\%:live,\\%1";
  //char	*str = "and r1,\\%0,r1";
  int	i = 0;
  int	cmptr_param = 0;

  fd = open("test.core",
	    O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
  if (fd != -1)
    {
      while (str[i])
	{
	  if (strncmp(&str[i], "sti", 3) == 0)
	    {
	      c = 0x0b;
	      write(fd, &c, 1);
	      c = 0;
	      i += 3;
	    }
	  if (strncmp(&str[i], "and", 3) == 0)
	    {
	      c = 0x06;
	      write(fd, &c, 1);
	      c = 0;
	      i += 3;
	    }
	  if (str[i] == ',')
	    cmptr_param++;
	  if (str[i] == 'r' && 0 <= str[i + 1] <= 9) /* REGISTRE ! */
	    {
	      if (cmptr_param == 0)
		c += 0b01000000;
	      else if (cmptr_param == 1)
		c += 0b00010000;
	      else if (cmptr_param == 2)
		c += 0b00000100;
	      else if (cmptr_param == 3)
		c += 0b01000001;
	      printf("Registre de taille %c - c = ", str[i + 1]);
	      affbin(c);
	      printf("\n");
	      i += 1;
	    }
	  if (str[i] == '\\' && str[i + 1] == '%') /* DIRECT */
	    {
	      if (cmptr_param == 0)
		c += 0b10000000;
	      else if (cmptr_param == 1)
		c += 0b00100000;
	      else if (cmptr_param == 2)
		c += 0b00001000;
	      else if (cmptr_param == 3)
		c += 0b01000010;
	      while (str[i + 1] != ',' && str[i + 1] != '\0')
		i++;
	      printf("Direct - c = ");
	      affbin(c);
	      printf("\n");
	    }
	  printf(">> %c\n", str[i]);
	  i++;
	}
      write(fd, &c, 1);
    }
  else
    printf("FAUX !\n");
  return (0);
}
