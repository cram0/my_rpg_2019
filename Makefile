NAME	=	my_rpg
SRC	=	$(wildcard *.c) \
		$(wildcard lib/*.c) \
		$(wildcard get_next_line/*.c) \
		$(wildcard components/**/*.c) \
		$(wildcard scenes/**/*.c) \
		$(wildcard scenes/**/**/*.c) \
		$(wildcard core/**/*.c) \
		$(wildcard generated_code/*.c) \
		$(wildcard mobs/*.c) \
		$(wildcard objects/*.c)
OBJ	=	$(SRC:.c=.o)
LDLIBS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm
CFLAGS	=	-O0 -g -g3 -Wno-discarded-qualifiers -Wno-incompatible-pointer-types -Wno-implicit-function-declaration

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