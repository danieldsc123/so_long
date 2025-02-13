/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:02:27 by danielda          #+#    #+#             */
/*   Updated: 2025/02/12 16:12:08 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			x * TILE_SIZE, y * TILE_SIZE);
}

int	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	mlx_do_sync(game->mlx);
	return (0);
}

void	load_image(t_game *game, void **img, char *path)
{
	int	img_x;
	int	img_y;

	img_x = TILE_SIZE;
	img_y = TILE_SIZE;
	*img = mlx_xpm_file_to_image(game->mlx, path, &img_x, &img_y);
	if (!*img)
	{
		write(2, "Error: Failed to load ", 24);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		exit_game(game);
		exit(1);
	}
}

void	init_images(t_game *game)
{
	load_image(game, &game->wall, "image/wall.xpm");
	load_image(game, &game->floor, "image/floor.xpm");
	load_image(game, &game->exit, "image/exit.xpm");
	load_image(game, &game->player, "image/player.xpm");
	load_image(game, &game->collectible, "image/collectible.xpm");
}
