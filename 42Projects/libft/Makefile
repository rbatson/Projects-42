# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 22:28:11 by rbatson           #+#    #+#              #
#    Updated: 2021/10/26 15:56:28 by rbatson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = 	ft_bzero.c		\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isalnum.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_strlen.c		\
		ft_memset.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_strchr.c		\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strncmp.c	\
		ft_memchr.c		\
		ft_strrchr.c	\
		ft_memcmp.c		\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_strnstr.c 	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_atoi.c 		\
		ft_strdup.c		\
		ft_calloc.c 	\
		ft_substr.c 	\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_itoa.c		\
		ft_split.c
 

OBJS = ${SRCS:.c=.o}
RM = rm -f
LIBC = ar rc
LIBR = ranlib

all: ${NAME}

$(NAME):
	${CC} ${FLAGS} -c ${SRCS} ${HEAD}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}
clean:
	${RM} $(OBJS)
fclean: clean
	${RM} $(NAME)
re: fclean all
