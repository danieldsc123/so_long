# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielda <danielda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 19:35:48 by danielda          #+#    #+#              #
#    Updated: 2024/12/19 17:51:09 by danielda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx-linux ./minilibx_opengl
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lbsd

SRCS = srcs/so_long.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -Iincludes -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(INCLUDES)

clean:
	@make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

