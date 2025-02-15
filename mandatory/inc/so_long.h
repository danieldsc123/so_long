/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:12:51 by danielda          #+#    #+#             */
/*   Updated: 2025/02/15 19:50:16 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../library/minilibx-linux/mlx.h"
# include "../../library/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <string.h> 
# include <ctype.h>

# define TILE_SIZE 32
# define WND_NAME "so_long"
# define WINDOW_WIDTH 700
# define WINDOW_HEIGHT 600

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'p'
# define EXIT 'E'
# define COLLECTIBLE 'C'

# define KEY_ESC 65307
# define KEY_W   119
# define KEY_A   97 
# define KEY_S   115
# define KEY_D   100

typedef struct s_map
{
	char	**map;
	int		fd;
	int		i;
	char	*line;
	int		y;
	int		x;
	int		count;
	int		j;
	char	**lines;
	void	*mlx;
	void	*win;
	int		width;
	int		height;

}t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collectible;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		map_width;
	int		map_height;
	int		steps;
	int		count_player;
	int		count_exit;
}t_game;

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;

}t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	int		remaining_collectibles;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_img;
	void	*floor_img;
	void	*exit_img;
	void	*collectible_img;
	void	*player_img;
	t_map	*map;
	t_img	*img;
}t_data;

int		is_valid_extension(char *file);
int		is_map_rectangular(char **map);
int		is_map_closed(char **map);
int		main(int argc, char **argv);
int		render_map(t_game *game);
int		count_chars(char **map, char c);
int		validate_map(t_game *game);
int		handle_key(int key, void *param);
int		find_player_x(char **map);
int		find_player_y(char **map);
int		get_map_width(char **map);
int		get_map_height(char **map);
int		handle_exit(void *param);
int		is_valid_path(t_game *game);
int		check_unreachable(t_game *game, char **map_copy);
int		execute_map_validations(t_game *game);
int		components_check_maps(t_game *game);
void	load_textures(t_game *game);
void	render_tile(t_game *game, char tile, int x, int y);
void	move_player(t_game *game, int px, int py);
void	process_movement(t_game *game, int px, int py);
void	print_map(char **map);
void	ft_draw_wall(int x, int y, t_data data);
void	ft_draw_floor(int x, int y, t_data data);
void	ft_draw_collectible(int x, int y, t_data data);
void	ft_init_player(int x, int y, t_data data);
void	ft_draw_exit(int x, int y, t_data data);
void	exit_game(t_game *game);
void	print_map_term(char **argv);
void	print_map(char **map);
void	initialize_game(t_game *game, char *map_path);
void	init_images(t_game *game);
void	load_image(t_game *game, void **img, char *path);
void	free_game(t_game *game);
void	set_to_null(t_game *game);
void	free_map(char **map);
void	flood_fill(char **map, int x, int y);
char	*get_next_line(int fd);
char	**load_map(const char *file_path);
char	**copy_map(char **map);
char	allocate_map(t_game *game);
char	**read_map(char *file);
int		parse_map(int argc, char **argv);
#endif