/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:12:51 by danielda          #+#    #+#             */
/*   Updated: 2025/01/14 13:44:25 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "../inc/get_next_line.h"
//# include "/full/path/to/so_long/get_next_line.h"
//# include "../../libft/get_next_line.h"
# include "../../libft/libft.h"
# include "../../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define TILE_SIZE 32
# define WIDTH	1000
# define HEIGHT	1000
# define UP      13
# define DOWN    1
# define LEFT    0
# define RIGHT   2
# define ESC     53
# define IMG_PXL 50
# define WND_NAME "so_long"

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
}t_game;

char	**read_map(const char *file);
int		main(int argc, char **argv);
void	load_textures(t_game *game);
void	render_map(t_game *game);
int		surrounded_by_walls(char **map);
int		count_chars(char **map, char c);
int		validate_map(char **map);
void	move_player(t_game *game, int px, int py);
int		handle_key(int key, t_game *game);

#endif