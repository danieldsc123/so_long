/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:21:27 by danielda          #+#    #+#             */
/*   Updated: 2025/02/08 19:25:32 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_player(t_game *game, int px, int py)
{
	char	*step_count;

	game->collectibles = count_chars(game->map, 'C');
	if (game->map[py][px] == 'C')
		game->collectibles--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = px;
	game->player_y = py;
	game->steps++;
	step_count = ft_itoa(game->steps);
	if (!step_count)
		return ;
	write(1, "move: ", 8);
	write(1, step_count, ft_strlen(step_count));
	write(1, "\n", 1);
	free(step_count);
	if (game->map[py][px] == 'E' && game->collectibles == 0)
		exit_game(game);
	game->map[py][px] = 'P';
	render_map(game);
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
	if (game->map[py][px] == 'E' && game->collectibles > 0)
		return (0);
	if (game->map[py][px] != '1')
		move_player(game, px, py);
	return (0);
}
