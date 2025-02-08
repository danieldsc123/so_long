/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:29:38 by danielda          #+#    #+#             */
/*   Updated: 2025/02/08 20:09:28 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_surrounded_by_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if ((i == 0 || (map[i + 1] == NULL && map[i][j] != '1')))
				return (0);
			if ((j == 0 || (map[i][j + 1] == '\0' && map[i][j] != '1')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_chars(char **map, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

int	validate_map(char **map)
{
	if (!is_surrounded_by_walls(map))
		return (0);
	if (count_chars(map, 'P') != 1)
		return (0);
	if (count_chars(map, 'E') != 1)
		return (0);
	if (count_chars(map, 'C') < 1)
		return (0);
	return (1);
}
