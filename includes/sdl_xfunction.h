/*
** sdl_xfunction.h for sdl_xfunction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 17:30:00 2014 Geoffrey Merran
** Last update Tue Apr  8 19:51:25 2014 Geoffrey Merran
*/

#ifndef SDL_XFUNCTION_
# define SDL_XFUNCTION_
# include <SDL/SDL.h>
# include "xfunction.h"

void		xSDL_Init(Uint32 flags);
SDL_Surface	*xSDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);

#endif /* SDL_XFUNCTION_ */
