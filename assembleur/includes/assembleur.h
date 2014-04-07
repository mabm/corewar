/*
** assembleur.h for  in /home/mediav_j/corewar/assembleur/includes
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:03:51 2014 Jeremy Mediavilla
** Last update Mon Apr  7 11:38:47 2014 Jeremy Mediavilla
** Last update Wed Apr  2 17:26:42 2014 Jeremy Mediavilla
*/

#ifndef COREWAR_H
# define COREWAR_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <byteswap.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_labels t_labels;
struct s_labels
{
  int	offset;
  char	name[128];
  
};

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <byteswap.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "op.h"

typedef struct	s_instruction
{
  int		fd;
  char		*str;
  int		i;
  int		ibase;
  char		c;
  int		ret_chck;
  int		cmptr;
}		t_instruction;

typedef struct s_system t_system;
struct s_system
{
  char		***cmd_asm;
  char		*name;
  char		*comment;
  int		nb_comment;
  int		nb_name;
  int		f_c;
  int		f_n;
  int		wm;
  t_labels	labels[128];
  t_instruction	ins;
};

typedef union u_conv t_conv;
union u_conv
{
  char	octets[4];
  int	value;
  int	fd;
};

/* fonctions dans init.c */
char		**init_tab();
void		init_cmd_asm(t_system *);
void		init(int, char **);
void		header_init1(int *, t_system *, int, int *);

/* fonctions dans pars.c */
void		parse_name(char *, int, t_system *);
void		parse_comment(char *, int, t_system *);
int		parse_line_cn(char *, t_system *, int);
void		parse_list_asm(t_system *);

/* fonctions dans aff.c */
void		affbin(unsigned);
void		aff_error(char *);
void		aff_info(t_system *, char *);

/* fonctions dans instruction1.c */
void		live_instruction(t_system *);
void		ld_instruction(t_system *);
void		st_instruction(t_system *);
void		add_instruction(t_system *);
void		sub_instruction(t_system *);

/* fonctions dans instruction2.c */
void		and_instruction(t_system *);
void		or_instruction(t_system *);
void		xor_instruction(t_system *);
void		zjmp_instruction(t_system *);
void		ldi_instruction(t_system *);

/* fonctions dans instruction3.c */
void		sti_instruction(t_system *);
void		fork_instruction(t_system *);
void		lfork_instruction(t_system *);
void		lld_instruction(t_system *);
void		lldi_instruction(t_system *);

/* fonction dans instruction4.c */
void		aff_instruction(t_system *);

/* fonctions dans data.c */
void		dir_data_condition(int, t_conv *, int);
void		write_reg_data(char *, int *, t_conv *, int);
void		write_undir_data(char *, int *, t_conv *, int);
void		write_dir_data(char *, int *, t_conv *, int);
void		write_data(int, char *, int);

/* fonctions dans file.c */
void		register_condition(t_system *);
void		direct_condition(t_system *);
void		indirect_condition(t_system *);
void		write_to_file(char *, int);

/* fonction dans magic.c */
void		write_magic(int);

/* fonctions dans tread.c */
void		tread_line(char *, t_system *, int);
void		tread_file(char *, t_system *);
void		tread_line_cnf_asm(t_system *, char *, int);

/* fonctions dans main.c */
void		create_header(int, t_system *, int);
int		check_instruction(t_system *);
void		check_ext(int, char **);
int		main(int, char **);

#endif /* COREWAR_H */