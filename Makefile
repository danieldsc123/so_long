# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielda <danielda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 19:35:48 by danielda          #+#    #+#              #
#    Updated: 2025/01/08 13:06:46 by danielda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 20:16:54 by asilveir          #+#    #+#              #
#    Updated: 2024/12/09 16:51:20 by asilveir         ###   ########.fr        #
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

# Compilators and flags
CC = cc
CFLAGS = -I$(INC_DIR) -Ilibft
MLX_DIR = ./minilibx-linux

# Libft directories
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Link flags
LDFLAGS = -L$(LIBFT_DIR) -lft -lX11 -lXext -lmlx

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