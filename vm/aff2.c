/*
** aff2.c for aff in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Apr  9 18:30:36 2014 Geoffrey Merran
** Last update Wed Apr  9 19:01:37 2014 Geoffrey Merran
*/

#include "aff.h"

void		init_sdl_header(t_win *win)
{
  SDL_Surface	*text;
  SDL_Rect	pos;

  pos.x = 26;
  pos.y = 30;
  text = TTF_RenderText_Solid(win->police, "Current Cycle : ", win->color);
  SDL_BlitSurface(text, NULL, win->screen, &pos);
  pos.x = 750;
  pos.y = 30;
  text = TTF_RenderText_Solid(win->police, "Cycle to die : ", win->color);
  SDL_BlitSurface(text, NULL, win->screen, &pos);
  pos.x = 26;
  pos.y = 60;
  text = TTF_RenderText_Solid(win->police, "Processus : ", win->color);
  SDL_BlitSurface(text, NULL, win->screen, &pos);
  SDL_FreeSurface(text);
}

void		init_color(t_win *win, t_champ *champ)
{
  t_champ	*tmp;
  int		c;
  Uint32	color[4];

  color[0] = SDL_MapRGB(win->screen->format, 255, 0, 0);
  color[1] = SDL_MapRGB(win->screen->format, 0, 0, 255);
  color[2] = SDL_MapRGB(win->screen->format, 0, 255, 0);
  color[3] = SDL_MapRGB(win->screen->format, 205, 173, 0);
  c = 0;
  tmp = champ;
  while (tmp)
    {
      tmp->color = color[c++];
      tmp = tmp->next;
    }
}
