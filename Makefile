##
## EPITECH PROJECT, 2021
## B-PSU-100-RUN-1-1-myls-yann.joubert
## File description:
## Makefile
##

SRC		=	main.c	\
			minishell1.c \
			utils.c \
			my_cd.c \
			my_setenv.c \
			utils_caract.c \
			my_unsetenv.c \
			my_exit.c	\
			build_in.c \

OBJ		=	$(SRC:.c=.o)

NAME	=	mysh

UTN		=	unit_tests

UTS		=	lib/my/my_strlen.c	\
			tests/Tests_funct.c \
			tests/Tests_my_printf.c \
			tests/Tests_funct2.c \
			lib/my/my_putstr.c	\
			lib/my/my_strcat.c \
			lib/my/my_putchar.c \
			lib/my/my_strncmp.c \
			lib/my/my_printf.c \
			lib/my/my_put_nbr3.c \
			lib/my/my_printf_putchar.c \
			lib/my/my_printf_putnbr.c \
			lib/my/my_printf_putstr.c \
			lib/my/my_convert_base.c \
			lib/my/my_printf_convert_base.c	\
			lib/my/my_strcmp.c \
			lib/my/my_strdup.c \
			lib/my/my_getnbr.c

UTFLAGS	=	-lcriterion --coverage

LIBMY 	= 	-L./lib/my/ -lmy

CFLAGS	=	-I ./include -W -Wall -Werror -Wextra -g3

all: 	$(NAME)

tests_run: fclean
	$(CC) -o $(UTN) $(UTS) $(UTFLAGS) $(CFLAGS)
	./$(UTN)

build_lib:
	make -C lib/my/ all

$(NAME): build_lib
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(LIBMY)

clean:
	make -C lib/my/ clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/my/ fclean
	rm -f $(NAME)
	rm -f libmy.a
	rm -f *gcda
	rm -f *gcno
	rm -f $(UTN)

re: fclean all
