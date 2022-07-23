NAME = philo
FLAGS = -Wall -Wextra -Werror
OBJS =	main.o\
    	init.o\
    	processes.o\
    	utils.o
HDRS = 	philo.h

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	gcc $(FLAGS) -o $@ $(OBJS) -I$(HDRS) $(LIBS)

%.o: %.c $(HDRS)
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all