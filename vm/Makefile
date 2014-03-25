##
## Makefile for Makefile in /home/merran_g/work/c_piscine/Piscine-C-Jour_11/do-op
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Mon Oct 21 13:28:05 2013 Geoffrey Merran
## Last update Tue Mar 25 16:39:22 2014 Geoffrey Merran
##

RM	= rm -f

CC	= cc

CFLAGS	+= -Werror -Wall -W -pedantic -ansi -I$(I_PATH)
I_PATH	= ../includes/

NAME	= exo

OBJ	= $(SRC:.c=.o)

LIB	= ../libmy/

SRC	= main.c

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
