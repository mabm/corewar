/*
** aff3.c for aff3 in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Apr  9 23:02:55 2014 Geoffrey Merran
** Last update Wed Apr  9 23:07:23 2014 Geoffrey Merran
*/

#include "aff.h"

void		aff_color_champ(int x, int y, t_win *win, t_champ *champ)
{
  SDL_Rect	*pos;

  pos = my_xmalloc(sizeof(*pos));
  pos->x = x;
  pos->y = y;
  pos->w = 20;
  pos->h = 20;
  SDL_FillRect(win->screen, pos, champ->color);
  free(pos);
}
