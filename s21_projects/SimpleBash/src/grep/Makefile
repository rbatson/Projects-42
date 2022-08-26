NAME = s21_grep
CC = gcc -std=c11 -D_GNU_SOURCE
CFLAGS = -Wall -Wextra -Werror
SRC = s21_grep.c
OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

cpplint:
	python3.10 ../../materials/linters/cpplint.py s21_grep.*

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all