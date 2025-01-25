/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:52:37 by danielda          #+#    #+#             */
/*   Updated: 2025/01/22 20:49:39 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
//#include <mlx.h>
#include <stdlib.h>

void	load_textures(t_game *game)
{
	int	size;

	size = 32;
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"image/wall.xpm", &size, &size);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"image/floor.xpm", &size, &size);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"image/player.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"image/exit.xpm", &size, &size);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"image/collectible.xpm", &size, &size);
	if (!game->wall || !game->floor || !game->player
		|| !game->exit || !game->collectible)
	{
		write(2, "Error\nFailed to load textures\n", 31);
		exit(1);
	}
}
