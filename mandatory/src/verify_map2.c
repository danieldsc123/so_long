/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:03:48 by danielda          #+#    #+#             */
/*   Updated: 2025/02/13 21:33:56 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../inc/so_long.h"

int	components_check_maps(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] != 'P' && game->map[i][j] != 'E' \
				&& game->map[i][j] != 'C' && game->map[i][j] != '1' \
				&& game->map[i][j] != '0')
				return (ft_putstr_fd("ERROR: NEED ALL COMPONENTS", 2), 0);
			else if (game->map[i][j] == 'P')
				game->count_player++;
			else if (game->map[i][j] == 'E')
				game->count_exit++;
			j++;
		}
		i++;
	}
	if (!--game->count_player && !--game->count_exit && game->collectibles)
		return (1);
	return (ft_putstr_fd("ERROR: INVALID COMPONENT", 2), 0);
}

// void	count_elements(char **map, int *values)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (map[i] != NULL)
// 	{
// 		j = 0;
// 		while (map[i][j] != '\n' && map[i][j] != '\0')
// 		{
// 			if (map[i][j] == 'P')
// 				values[0]++;
// 			else if (map[i][j] == 'E')
// 				values[1]++;
// 			else if (map[i][j] == 'C')
// 				values[2]++;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	check_duplicates(char **map)
// {
// 	int	*values;

// 	values = (int *)malloc(3 * sizeof(int));
// 	if (!values)
// 		return (0);
// 	values[0] = 0;
// 	values[1] = 0;
// 	values[2] = 0;

// 	count_elements(map, values);
// 	if (values[0] != 1 || values[1] != 1 || values[2] < 1)
// 	{
// 		free(values);
// 		return (0);
// 	}
// 	free(values);
// 	return (1);
// }
