/*
** aff.c for aff in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 19:31:35 2014 Geoffrey Merran
** Last update Wed Apr  9 00:54:39 2014 Geoffrey Merran
*/

#include "aff.h"

void	init_window(SDL_Surface **screen)
{
  xSDL_Init(SDL_INIT_VIDEO);
  *screen = xSDL_SetVideoMode(SIZE_X, SIZE_Y, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Corewar 2014", NULL);
}

Uint32		get_case_color(t_arena *arena, int address, t_proc *procs,
			       SDL_Surface *screen)
{
  t_proc	*tmp;

  tmp = procs;
  while (tmp)
    {
      if (address == tmp->pc)
	return (SDL_MapRGB(screen->format, 0, 255, 255));
      tmp = tmp->next;
    }
  if (arena->color[address] == 1)
    return (SDL_MapRGB(screen->format, 255, 0, 0));
  if (arena->color[address] == 2)
    return (SDL_MapRGB(screen->format, 0, 0, 255));
  return (SDL_MapRGB(screen->format, 0, 0, 0));
}

void		aff_arena(SDL_Surface *screen, t_arena *arena, t_proc *procs)
{
  int		i;
  SDL_Rect	*pos;

  i = 0;
  pos = my_xmalloc(sizeof(*pos));
  pos->x = 26;
  pos->y = 200;
  pos->w = PLOT_W;
  pos->h = PLOT_H;
  while (i < MEM_SIZE)
    {
      SDL_FillRect(screen, pos, get_case_color(arena, i, procs, screen));
      pos->x += pos->w + SEP_W;
      if (pos->x >= SIZE_X - 26)
	{
	  pos->x = 26;
	  pos->y += pos->h + SEP_H;
	}
      i++;
    }
  SDL_Flip(screen);
}
