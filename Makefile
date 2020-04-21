NAME	=	my_rpg
SRC	=	$(wildcard *.c) \
		$(wildcard lib/*.c) \
		$(wildcard get_next_line/*.c) \
		$(wildcard components/**/*.c) \
		$(wildcard scenes/**/*.c) \
		$(wildcard core/**/*.c)
OBJ	=	$(SRC:.c=.o)
LDLIBS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm
CFLAGS	=	-O0 -g -g3

all: $(NAME)

$(NAME): $(OBJ)

re:
	make fclean
	make all

clean:
	find -name '*.o' -exec rm {} \;

fclean:
	make clean
	rm -f $(NAME)