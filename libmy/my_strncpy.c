/*
** my_strncpy.c for my_strncpy in /home/merran_g/work/c_piscine/Piscine-C-Jour_06
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 10:11:43 2013 Geoffrey Merran
** Last update Tue Oct  8 09:44:38 2013 Geoffrey Merran
*/

char *my_strncpy(char *dest, char *src, int n)
{
  int	i;

  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  while (i < n)
    {
      dest[i] = '\0';
      i++;
    }
  return (dest);
}
