/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_height.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:23:41 by danielda          #+#    #+#             */
/*   Updated: 2025/01/29 16:57:20 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_width(char **map_data)
{
	char	**map;

	map = map_data;
	if (!map[0])
		return (0);
	return (ft_strlen(map[0]) - 1);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
	height++;
	return (height);
}
