##
## Makefile for Makefile in /home/merran_g/work/c_piscine/Piscine-C-Jour_11/do-op
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Mon Oct 21 13:28:05 2013 Geoffrey Merran
## Last update Thu Mar 27 19:15:28 2014 Geoffrey Merran
##

RM	= rm -f

CC	= cc

CFLAGS	+= -Wextra -Wall -W -pedantic -g3 -ansi -I$(I_PATH)
I_PATH	= ../includes/

NAME	= corewar

OBJ	= $(SRC:.c=.o)

LIB	= ../libmy/

SRC	= main.c vm_pars.c \
	xfunction.c

all:		libs $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lmy -L$(LIB)

libs:
	make -C $(LIB)

clean:
	(cd $(LIB); make clean)
	$(RM) $(OBJ)

fclean:		clean
	(cd $(LIB); make fclean)
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
