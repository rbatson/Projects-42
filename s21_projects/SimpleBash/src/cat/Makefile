NAME= s21_cat
CC= gcc -std=c11 -D_GNU_SOURCE
CFLAGS= -Wall -Wextra -Werror
CAT= s21_cat.c

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(CAT) -o $(NAME)

clean:
		rm -rf *.a *.out *.o *.txt
fclean:
		rm -rf $(NAME)
re:
		make fclean
		make all
		rm -rf *.o *.a
