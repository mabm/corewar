##
## Makefile for Makefile in /home/merran_g/work/c_piscine/Piscine-C-Jour_11/do-op
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Mon Oct 21 13:28:05 2013 Geoffrey Merran
## Last update Wed Apr  9 15:26:57 2014 Geoffrey Merran
##

RM	= rm -f

CC	= cc

CFLAGS	+= -Wextra -Wall -W -pedantic -g3 -ansi -I$(I_PATH)
I_PATH	= ../includes/

NAME	= corewar

OBJ	= $(SRC:.c=.o)

LIB	= ../libmy/

SRC	= main.c  \
	vm_pars.c \
	vm_init.c \
	vm_getchamp.c vm_getchamp2.c \
	vm_arena.c vm_arena2.c \
	vm_instruction.c \
	vm_instruction2.c \
	vm_instruction3.c \
	vm_instruction4.c \
	vm_proc.c \
	aff.c \
	op.c \
	my_free.c \
	xfunction.c \
	sdl_xfunction.c \

all:		libs $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lmy -L$(LIB) -lSDL -lSDL_ttf

libs:
	make -C $(LIB)

clean:
	(cd $(LIB); make clean)
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)
	(cd $(LIB); make fclean)

re:		fclean all

.PHONY:		all clean fclean re
