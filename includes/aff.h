/*
** aff.h for aff in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 19:33:03 2014 Geoffrey Merran
** Last update Wed Apr  9 14:52:39 2014 Geoffrey Merran
*/

#ifndef AFF_
# define AFF_
# define SIZE_X 1280
# define SIZE_Y 720
# define PLOT_W 8
# define PLOT_H 8
# define SEP_W 2
# define SEP_H 2
# define BPP 32
# include "vm_corewar.h"
# include "sdl_xfunction.h"

void	init_window(t_win *win);
void	aff_arena(t_win *win, t_arena *arena, t_proc *procs);
void   	aff_window(t_win *win, t_arena *arena,
		   t_proc *procs, t_cycles *cycles);

#endif /* AFF_ */
