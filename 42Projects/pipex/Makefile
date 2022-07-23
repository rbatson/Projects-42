# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 23:26:22 by rbatson           #+#    #+#              #
#    Updated: 2022/03/26 16:10:31 by rbatson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = pipex.h

SRC = pipex.c pipex-utils.c

OBJ = $(SRC:c=o)

SRCB = pipex-bonus.c pipex-utils.c

OBJB = $(SRCB:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean:
	rm -f $(OBJ) $(OBJB)
	rm -f $(NAME)

re: fclean all

bonus: $(OBJB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJB)

.PHONY: clean fclean re bonus
