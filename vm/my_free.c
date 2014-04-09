/*
** my_free.c for my_free in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Apr  7 10:19:02 2014 Geoffrey Merran
** Last update Wed Apr  9 22:31:42 2014 Geoffrey Merran
*/

#include "my_free.h"

void		free_champ(t_champ **champs)
{
  t_champ	*tmp;

  while (*champs)
    {
      tmp = (*champs)->next;
      free(*champs);
      *champs = tmp;
    }
}

void		free_proc(t_proc **proc)
{
  t_proc	*tmp;

  while (*proc)
    {
      tmp = (*proc)->next;
      free(*proc);
      *proc = tmp;
    }
}

void		free_battle(inst *instruction, t_win *win, t_proc **proc)
{
  free_proc(proc);
  TTF_CloseFont(win->police);
  TTF_Quit();
  SDL_Quit();
  free(instruction);
}
