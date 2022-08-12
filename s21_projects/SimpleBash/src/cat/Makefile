NAME = s21_cat
CC = gcc -std=c11 -D_GNU_SOURCE
CFLAGS = -Wall -Wextra -Werror
SRC = s21_cat.c
OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all