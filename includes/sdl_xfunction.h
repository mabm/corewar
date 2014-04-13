/*
** sdl_xfunction.h for sdl_xfunction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 17:30:00 2014 Geoffrey Merran
** Last update Sat Apr 12 20:35:33 2014 Geoffrey Merran
*/

#ifndef SDL_XFUNCTION_
# define SDL_XFUNCTION_
# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include "xfunction.h"

typedef struct	s_win
{
  SDL_Surface	*screen;
  TTF_Font	*police;
  SDL_Color	color;
}		t_win;

void		xSDL_Init(Uint32 flags);
void		xTTF_Init();
TTF_Font	*xTTF_OpenFont(char *path, int size);
SDL_Surface	*xSDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);

#endif /* SDL_XFUNCTION_ */
