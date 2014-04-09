/*
** vm_arena2.c for  in /home/nicolas/Workspace/Corewar/vm
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Thu Apr  3 14:19:48 2014 Nicolas Ades
** Last update Wed Apr  9 18:01:05 2014 Geoffrey Merran
*/

#include "vm_arena.h"

void		reset_pc(t_proc *proc)
{
  t_proc	*tmp;

  tmp = proc;
  while (tmp != NULL)
    {
      tmp->alive = 0;
      tmp = tmp->next;
    }
}

int		one_winner(t_proc *proc, t_champ *champ)
{
  int		nb_alive;
  t_champ	*tmp_ch;

  nb_alive = 0;
  tmp_ch = champ;
  while (tmp_ch != NULL)
    {
      if (tmp_ch->live > 0)
	{
	  nb_alive++;
	  tmp_ch->live = 0;
	}
      tmp_ch = tmp_ch->next;
    }
  reset_pc(proc);
  if (nb_alive < 2)
    return (1);
  return (0);
}

void		who_win(t_champ *champ)
{
  t_champ	*tmp;
  int		win;

  tmp = champ;
  win = 0;
  my_printf("\n");
  while (tmp)
    {
      if (tmp->live != 0)
	{
	  my_printf("Player n°%d is alive !\n", tmp->id);
	  win = 1;
	}
      tmp = tmp->next;
    }
  if (win == 0)
    my_printf("Nobody is alive\n");
}
