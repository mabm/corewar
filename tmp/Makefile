##
## Makefile for  in /home/mediav_j/corewar/tmp
## 
## Made by Jeremy Mediavilla
## Login   <mediav_j@epitech.net>
## 
## Started on  Wed Mar 26 17:05:38 2014 Jeremy Mediavilla
## Last update Thu Mar 27 11:14:49 2014 Jeremy Mediavilla
##

SRC	=	convert_base.c		\
		getnbr_base.c		\
		main.c			\
		strcmp.c		\

NAME	=	convert

CC	=	cc

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Werror -Wall -pedantic -ansi -g3 -ggdb

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
