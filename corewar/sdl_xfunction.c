/*
** sdl_xfunction.c for sdl_xfunction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 17:31:44 2014 Geoffrey Merran
** Last update Wed Apr  9 14:40:13 2014 Geoffrey Merran
*/

#include "sdl_xfunction.h"

void	xSDL_Init(Uint32 flags)
{
  if (SDL_Init(flags) == -1)
    my_error("SDL error : init fail\n");
}

void	xTTF_Init()
{
  if (TTF_Init() == -1)
    my_error("SDL TTf error : init fail\n");
}

SDL_Surface	*xSDL_SetVideoMode(int width, int height, int bpp, Uint32 flags)
{
  SDL_Surface	*screen;

  if ((screen = SDL_SetVideoMode(width, height, bpp, flags)) == NULL)
    my_error("SDL error : Setvideomode fail\n");
  return (screen);
}
