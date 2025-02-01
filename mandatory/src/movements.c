/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:21:27 by danielda          #+#    #+#             */
/*   Updated: 2025/01/31 21:03:23 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_player(t_game *game, int px, int py)
{
	if (game->map[py][px] == 'C')
		game->collectibles--;
	game->map[game->player_y][game->player_x] = '0';
	game->map[py][px] = 'P';
	game->player_x = px;
	game->player_y = py;
	render_map(game);
	if (game->collectibles == 0 && game->map[py][px] == 'E')
		exit_game(game);
}

int	handle_key(int key, void *param)
{
	int		px;
	int		py;
	t_game	*game;

	game = (t_game *)param;
	px = game->player_x;
	py = game->player_y;
	if (key == KEY_ESC)
		mlx_loop_end(game->mlx);
	else if (key == KEY_W)
		py--;
	else if (key == KEY_A)
		px--;
	else if (key == KEY_S)
		py++;
	else if (key == KEY_D)
		px++;
	if (px < 0 || py < 0 || px >= get_map_width(game->map)
		|| py >= get_map_height(game->map))
		return (0);
	if (game->map[py][px] != '1')
		move_player(game, px, py);
	return (0);
}
