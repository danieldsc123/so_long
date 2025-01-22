# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielda <danielda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 20:16:54 by asilveir          #+#    #+#              #
#    Updated: 2025/01/21 17:39:39 by danielda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do projeto
NAME = so_long

# Diretórios
SRC_DIR = ./mandatory/src
INC_DIR = ./mandatory/inc

# Lista de arquivos
SRC = mandatory/src/so_long.c \
       mandatory/src/map.c \
       mandatory/src/render_map.c \
       mandatory/src/validate_map.c \
       mandatory/src/exit.c \
       mandatory/src/map_downl.c \
       mandatory/src/print_map.c \
       mandatory/src/library_map_mlx.c \
       mandatory/src/width_height.c \
       mandatory/src/player_position.c \
	mandatory/src/render.c \
	mandatory/src/movements.c \

# Compiladores e flags
CC = cc -Wall -Wextra -Werror
CFLAGS = -I./mandatory/inc -I./library/minilibx-linux -I./library/libft

# Diretórios da Libft
LIBFT_DIR = ./library/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Flags de linkagem
MLX_DIR = ./library/minilibx-linux
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext

# Regra principal
all: $(LIBFT) $(NAME)

# Compilar o jogo
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Compilar a Libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Limpeza
clean:
	rm -rf $(NAME)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

# Recompilar
re: fclean all

# Executar com Valgrind
valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re valgrind
