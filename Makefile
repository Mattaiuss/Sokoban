##
## EPITECH PROJECT, 2023
## My_MAKEFILE
## File description:
## makefile.
##

NAME	=	my_sokoban

SRCS 	=	main.c	\
			my_putstr.c	\
			my_putchar.c	\
			my_put_nbr.c	\
			my_strlen.c	\
			movement.c	\
			fill_data.c	\
			corners.c	\
			my_strcmp.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS 	=	-Wall -Wextra -g3 -lncurses

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -f $(OBJS)
	rm -f *~

fclean: 	clean
	rm -f $(NAME)

re:	fclean all
