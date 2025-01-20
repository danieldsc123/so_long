/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:12:51 by danielda          #+#    #+#             */
/*   Updated: 2025/01/20 18:44:44 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "../inc/get_next_line.h"
//# include "/full/path/to/so_long/get_next_line.h"
//# include "../../libft/get_next_line.h"
//# include "../../libft/libft.h"
# include "../../library/minilibx-linux/minilibx-linux/mlx.h"
# include "../../library/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
// # include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <string.h> 

# define TILE_SIZE 32
# define WIDTH	900
# define HEIGHT	900
# define WND_NAME "so_long"
# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 300

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'p'
# define EXIT 'E'
# define COLLECTIBLE 'C'

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

// typedef struct s_img
// {
// 	void	*player_up;
// 	void	*player_left;
// 	void	*player_right;
// 	void	*player_down;
// 	void	*background;
// }				t_img;

char	**read_map(const char *file);
int		main(int argc, char **argv);
void	load_textures(t_game *game);
void	render_map(t_game *game);
int		surrounded_by_walls(char **map);
int		count_chars(char **map, char c);
int		validate_map(char **map);
void	move_player(t_game *game, int px, int py);
int		handle_key(int key, t_game *game);
char	**load_map(const char *file_path);
int		validate_map(char **map);
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
int		find_player_x(char **map);
int		find_player_y(char **map);
int		get_map_width(char **map);
int		get_map_height(char **map);

#endif