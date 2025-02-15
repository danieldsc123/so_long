/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:52:24 by danielda          #+#    #+#             */
/*   Updated: 2025/02/14 22:31:04 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || x >= (int)ft_strlen(map[y])
		|| map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'V';
		return ;
	}	
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**copy_map(char **map)
{
	int		i;
	char	**new_map;
	int		height;

	height = get_map_height(map);
	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

int	check_unreachable(t_game *game, char **map_copy)
{
	int	x;
	int	y;

	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if ((game->map[y][x] == 'C' || game->map[y][x] == 'E')
				&& map_copy[y][x] != 'V')
				return (0);
			x++;
		}
		y++;
	}
	free_map(map_copy);
	return (1);
}

int	is_valid_path(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map(game->map);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player_x, game->player_y);
	return (check_unreachable(game, map_copy));
}
