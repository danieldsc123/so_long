/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:21:27 by danielda          #+#    #+#             */
/*   Updated: 2025/02/12 16:30:19 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>

void	move_player(t_game *game, int px, int py)
{
	char	*step_count;

	step_count = NULL;
	game->collectibles = count_chars(game->map, 'C');
	if (game->map[py][px] == 'C')
		game->collectibles--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = px;
	game->player_y = py;
	game->steps++;
	step_count = ft_itoa(game->steps);
	write(1, "passo: ", 7);
	write(1, step_count, ft_strlen(step_count));
	free(step_count);
	write(1, "\n", 1);
	if (game->map[py][px] == 'E' && game->collectibles == 0)
		exit_game(game);
	game->map[py][px] = 'P';
	render_map(game);
}

void	process_movement(t_game *game, int px, int py)
{
	if (px < 0 || py < 0 || px >= get_map_width(game->map)
		|| py >= get_map_height(game->map) || game->map[py][px] == '1')
		return ;
	if (game->map[py][px] == 'E' && game->collectibles > 0)
		return ;
	move_player(game, px, py);
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
		exit_game(game);
	else if (key == KEY_W)
		process_movement(game, px, py - 1);
	else if (key == KEY_A)
		process_movement(game, px - 1, py);
	else if (key == KEY_S)
		process_movement(game, px, py + 1);
	else if (key == KEY_D)
		process_movement(game, px + 1, py);
	return (0);
}
