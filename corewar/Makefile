##
## Makefile for Makefile in /home/merran_g/work/c_piscine/Piscine-C-Jour_11/do-op
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Mon Oct 21 13:28:05 2013 Geoffrey Merran
## Last update Sun Apr 13 17:14:55 2014 Geoffrey Merran
##

RM	= rm -f

CC	= cc

CFLAGS	+= -Wextra -Wall -W -pedantic -O3 -ansi -I$(I_PATH)
I_PATH	= ../includes/

NAME	= corewar

FONT	= imagine_font.ttf

OBJ	= $(SRC:.c=.o)

LIB	= ../libmy/

SRC	= main.c  \
	vm_pars.c \
	vm_init.c \
	vm_getchamp.c vm_getchamp2.c vm_getchamp3.c \
	vm_arena.c vm_arena2.c \
	vm_instruction.c \
	vm_instruction2.c \
	vm_instruction3.c \
	vm_instruction4.c \
	vm_getparams.c \
	vm_getparams2.c \
	vm_getparams3.c \
	vm_proc.c \
	aff.c aff2.c aff3.c \
	op.c \
	my_free.c \
	xfunction.c \
	sdl_xfunction.c \

all:		libs $(NAME)

$(NAME):	$(OBJ)
	cp police/$(FONT) /tmp/
	$(CC) -o $(NAME) $(OBJ) -lmy -L$(LIB) -lSDL -lSDL_ttf -lSDL_mixer

libs:
	make -C $(LIB)

clean:
	(cd $(LIB); make clean)
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)
	$(RM) /tmp/$(FONT)
	(cd $(LIB); make fclean)

re:		fclean all

.PHONY:		all clean fclean re
