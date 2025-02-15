/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:48:51 by danielda          #+#    #+#             */
/*   Updated: 2025/02/14 22:57:46 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map && game->map[i])
		free(game->map[i++]);
	free(game->map);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->mlx && game->win)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
	}
	free(game->mlx);
	free(game);
	exit(0);
}
