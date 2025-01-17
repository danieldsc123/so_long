/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_downl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:18:31 by danielda          #+#    #+#             */
/*   Updated: 2025/01/17 16:34:05 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_draw_wall(int x, int y, t_data data)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.wall_img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	ft_draw_floor(int x, int y, t_data data)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.floor_img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	ft_draw_exit(int x, int y, t_data data)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.exit_img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	ft_draw_collectible(int x, int y, t_data data)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.collectible_img,
		x * TILE_SIZE, y * TILE_SIZE);
	data.remaining_collectibles++;
}

void	ft_init_player(int x, int y, t_data data)
{
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.player_img,
		x * TILE_SIZE, y * TILE_SIZE);
}
