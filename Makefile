
NAME	= bsq

SRC		=	bsq.c \
			bsq_ft.c \
			bsq_ft2.c \
			basic_ft.c

CFLAGS	= -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		gcc -c $(SRC) $(CFLAGS)
		gcc $(OBJ) -o $(NAME)
	
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
