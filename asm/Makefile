##
## Makefile for Makefile in /home/merran_g/work/c_elem/corewar/assembleur
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Sat Apr 12 20:15:17 2014 Geoffrey Merran
## Last update Sat Apr 12 20:15:28 2014 Geoffrey Merran
##

CC		=	gcc -Iincludes

CFLAGS		+=	-W -Wextra -Wall -ansi -pedantic -g3

RM		=	rm -f

SRC		=	src/main.c				\
			src/gnl.c				\
			src/init.c				\
			src/pars.c				\
			src/aff.c				\
			src/instruction1.c			\
			src/instruction2.c			\
			src/instruction3.c			\
			src/instruction4.c			\
			src/data.c				\
			src/file.c				\
			src/magic.c				\
			src/tread.c				\
			src/check_errors.c			\
			src/error_instruction1.c		\
			src/error_instruction2.c		\
			src/error_instruction3.c		\
			src/error_instruction4.c		\
			src/pof.c				\
			src/xfunctions.c			\

SRC_LOADING	=	makefile_deco/loading.c

OBJ		=	$(SRC:.c=.o)
OBJ_LOADING	=	$(SRC_LOADING:.c=.o)

NOM		=	asm
NAME_LOADING	=	makefile_deco/loading

all:		lib asm

asm:		$(OBJ)
		@echo -e "\n > COMPILATION DES .C ASSEMBLEUR EN COURS\n"
		$(CC) -o $(NOM) $(OBJ) -lmy -L ../libmy
		@echo -e "\n > COMPILATION DES .C ASSEMBLEUR TERMINEE"
		@cat ../makefile_deco/logins
		# @cat ../makefile_deco/girl2

lib:
		@echo -e "\n > COMPILATION DE LA LIB EN COURS\n"
		make -C ../libmy
		@echo -e "\n > COMPILATION DE LA LIB TERMINE\n"

clean:
		@echo -e "\t->>> SUPPRESSION DES .o <<<-"
		$(RM) $(OBJ)
		$(RM) $(OBJ_LOADING)
		(cd ../libmy ; make clean)

fclean:		clean
		@echo -e "\t->>> SUPPRESSION DE L'EXECUTABLE ET DE LA LIB <<<-"
		$(RM) $(NOM)
		$(RM) $(NAME_LOADING)
		(cd ../libmy ; make fclean)

re:		fclean all

.PHONY:		all lib clean fclean re
