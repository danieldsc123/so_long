/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:03:48 by danielda          #+#    #+#             */
/*   Updated: 2025/02/14 23:33:31 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../inc/so_long.h"

static	int	is_valid_component(char c, t_game *game)
{
	if (c == 'P')
		game->count_player++;
	else if (c == 'E')
		game->count_exit++;
	else if (c == 'C')
		game->collectibles++;
	else if (c != '1' && c != '0')
		return (0);
	return (1);
}

int	components_check_maps(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->count_player = 0;
	game->count_exit = 0;
	game->collectibles = 0;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (!is_valid_component(game->map[i][j], game))
				return (ft_putstr_fd("ERROR: NEED ALL COMPONENTS", 2), 0);
		}
	}
	if (game->count_player != 1 || game->count_exit != 1
		|| game->collectibles < 1)
		return (ft_putstr_fd("ERROR: INVALID COMPONENT", 2), 0);
	return (1);
}
