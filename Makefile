##
## Makefile for  in /home/mediav_j/corewar
## 
## Made by Jeremy Mediavilla
## Login   <mediav_j@epitech.net>
## 
## Started on  Thu Mar 27 18:08:19 2014 Jeremy Mediavilla
## Last update Fri Mar 28 16:13:33 2014 Jeremy Mediavilla
##

CC		=	gcc

CFLAGS		+=	-W -Wextra -Wall -ansi -pedantic -g3

RM		=	rm -f

SRC		=	assembleur/main.c				\
			assembleur/gnl.c				\

SRC_LOADING	=	makefile_deco/loading.c

OBJ		=	$(SRC:.c=.o)
OBJ_LOADING	=	$(SRC_LOADING:.c=.o)

NOM		=	assembleur/asm
NAME_LOADING	=	makefile_deco/loading

all:		lib asm

asm:		$(OBJ)
		@echo -e "\n > COMPILATION DES .C ASSEMBLEUR EN COURS\n"
		$(CC) -o $(NOM) $(OBJ) -lmy -L ./libmy
		@echo -e "\n > COMPILATION DES .C ASSEMBLEUR TERMINEE"
		@cat makefile_deco/logins
		# @cat makefile_deco/girl2

lib:
		@echo -e "\n > COMPILATION DE LA LIB EN COURS\n"
		make -C ./libmy
		@echo -e "\n > COMPILATION DE LA LIB TERMINE\n"

clean:
		@echo -e "\t->>> SUPPRESSION DES .o <<<-"
		$(RM) $(OBJ)
		$(RM) $(OBJ_LOADING)
		(cd ./libmy ; make clean)

fclean:		clean
		@echo -e "\t->>> SUPPRESSION DE L'EXECUTABLE ET DE LA LIB <<<-"
		$(RM) $(NOM)
		$(RM) $(NAME_LOADING)
		(cd ./libmy ; make fclean)

re:		fclean all

.PHONY:		all lib clean fclean re
