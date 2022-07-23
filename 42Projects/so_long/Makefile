NAME		=	so_long

SRCS_FILES	= 	${shell find ./source -name "*.c"}

UTILS_FILES	= 	${shell find ./Utils -name "*.c"}

SRCS		= 	$(SRCS_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))
SRCS_UTILS_FILES	=	$(UTILS_FILES)
OBJS_UTILS		=	$(patsubst %.c,%.o,$(SRCS_UTILS_FILES))

MLX_DIR		=	minilibx_mac
INCLUDE		=	-I./include -I./minilibx_mac

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -f

.PHONY:		all clean fclean re

all:		$(NAME)

%.o:		%.c include/so_long.h
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
		
$(NAME):	$(OBJS) $(OBJS_UTILS)
			@make -C $(MLX_DIR)
			@$(CC) $(CFLAGS) $(OBJS) $(OBJS_UTILS) $(INCLUDE) $(MLX_FLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_UTILS) 
			@make clean -C $(MLX_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all