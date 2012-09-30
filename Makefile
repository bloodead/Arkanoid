CC	=	gcc
CFLAGS	=	-W -Wall -Werror
LDFLAGS	=

NAME	=	id_arkanoid
SRCS	=	main.c			\
		bonus.c			\
		brick.c			\
		coli.c			\
		generic.c		\
		id_ball.c		\
		id_barre.c		\
		id_print_char.c		\
		id_print_nbr.c		\
		id_print_str.c		\
		tools.c
OBJS	=	$(SRCS:.c=.o)

make:
	$(CC) -o $(CFLAGS)

clean:
	rm -rf $(OBJS)

distclean:
	rn -rf $(OBJS)
	rm -rf $(NAME)
