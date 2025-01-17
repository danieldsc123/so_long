/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:02:27 by danielda          #+#    #+#             */
/*   Updated: 2025/01/17 16:34:34 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include "../inc/so_long.h"

void	render_map(t_game *game)
{
	int		y;
	int		x;
	void	*img;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			img = game->floor;
			if (game->map[y][x] == '1')
			img = game->wall;
			else if (game->map[y][x] == 'P')
			img = game->player;
			else if (game->map[y][x] == 'C')
			img = game->collectible;
			else if (game->map[y][x] == 'E')
			img = game->exit;
			mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
