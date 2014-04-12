/*
** test.c for testnb in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat Apr 12 18:38:46 2014 Geoffrey Merran
** Last update Sat Apr 12 18:40:23 2014 Geoffrey Merran
*/

typedef union u_nion
{
  char octet[4];
  int integer;
}		t_conv;

int		main()
{
  t_conv	conv;

  conv.octet[3] = 0xff;
  conv.octet[2] = 0xff;
  conv.octet[1] = 0xff;
  conv.octet[0] = 0xc4;
  printf("%d\n", conv.integer);
}
