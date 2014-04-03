/*
** assembleur.h for  in /home/mediav_j/corewar/assembleur/includes
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:03:51 2014 Jeremy Mediavilla
** Last update Thu Apr  3 15:20:14 2014 Joris Bertomeu
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
void		live_instruction(int, char *, int *, int *, char *, int *);
void		ld_instruction(int, char *, int *, int *, char *, int *);
void		st_instruction(int, char *, int *, int *, char *, int *);
void		add_instruction(int, char *, int *, int *, char *, int *);
void		sub_instruction(int, char *, int *, int *, char *, int *);

/* fonctions dans instruction2.c */
void		and_instruction(int, char *, int *, int *, char *, int *);
void		or_instruction(int, char *, int *, int *, char *, int *);
void		xor_instruction(int, char *, int *, int *, char *, int *);
void		zjmp_instruction(int, char *, int *, int *, char *, int *);
void		ldi_instruction(int, char *, int *, int *, char *, int *);

/* fonctions dans instruction3.c */
void		sti_instruction(int, char *, int *, int *, char *, int *);
void		fork_instruction(int, char *, int *, int *, char *, int *);
void		lfork_instruction(int, char *, int *, int *, char *, int *);
void		lld_instruction(int, char *, int *, int *, char *, int *);
void		lldi_instruction(int, char *, int *, int *, char *, int *);

/* fonction dans instruction4.c */
void		aff_instruction(int, char *, int *, int *, char *, int *);

/* fonctions dans data.c */
void		dir_data_condition(int, t_conv *, int);
void		write_reg_data(char *, int *, t_conv *, int);
void		write_undir_data(char *, int *, t_conv *, int);
void		write_dir_data(char *, int *, t_conv *, int);
void		write_data(int, char *, int);

/* fonctions dans file.c */
void		register_condition(int *, char *, int *, char *);
void		direct_condition(int *, char *, int *, char *);
void		indirect_condition(int *, char *, int *, char *);
void		write_to_file(char *, int);

/* fonction dans magic.c */
void		write_magic(int);

/* fonctions dans tread.c */
void		tread_line(char *, t_system *, int);
void		tread_file(char *, t_system *);
void		tread_line_cnf_asm(t_system *, char *, int);

/* fonctions dans main.c */
void		create_header(int, t_system *, int);
int		check_instruction(char *, char *, int *, int *, int);
void		check_ext(int, char **);
int		main(int, char **);

#endif /* COREWAR_H */
