# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielda <danielda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 20:16:54 by asilveir          #+#    #+#              #
#    Updated: 2025/01/17 17:35:02 by danielda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Src directory
SRC_DIR = ./mandatory/src
INC_DIR = ./mandatory/inc

# List of files
SRC = mandatory/src/so_long.c \
       mandatory/src/map.c \
       mandatory/src/render_map.c \
       mandatory/src/validate_map.c \
	mandatory/src/exit.c \
	mandatory/src/map_downl.c \
	mandatory/src/print_map.c \

# Compilators and flags
CC = cc
# CFLAGS = -I$(INC_DIR) -Ilibft
MLX_DIR = ./library/minilibx-linux
CFLAGS = -I./mandatory/inc -I./library/minilibx-linux -I./library/libft

# Libft directories
LIBFT_DIR = ./library/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Link flags
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext


# Main rule
all: $(LIBFT) $(NAME)

# Compile the game
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Compile Libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Cleaning
clean:
	rm -rf $(NAME)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

# Rebuild
re: fclean all

.PHONY: all clean fclean re

