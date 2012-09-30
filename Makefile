NAME	=	id_arkanoid
SRCS	=	main.c		\
		bonus.c		\
		brick.c		\
		coli.c		\
		generic.c	\
		id_ball.c	\
		id_barre.c	\
		id_print_str.c	\
		id_print_char.c	\
		id_print_nbr.c	\
		tools.c

OBJS	=	$(SRCS:.c=.o)
LIBS	=	-ltermcap
CC	=	gcc -W -Wall -Werror
CFLAGS	=
LDFLAGS	=

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)

distclean:	clean
	rm -f $(NAME)

rebuild:	distclean all

