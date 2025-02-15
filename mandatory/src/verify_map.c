/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:32:30 by danielda          #+#    #+#             */
/*   Updated: 2025/02/14 19:52:18 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../inc/so_long.h"

int	is_valid_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	return (len > 4 && ft_strcmp(file + len - 4, ".ber") == 0);
}

int	is_map_rectangular(char **map)
{
	int	i;
	int	width;
	int	len;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	if (map[0][width - 1] == '\n')
		width--;
	i = 1;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			len--;
		if (len != width)
			return (0);
		i++;
	}
	return (1);
}

int	is_map_closed(char **map)
{
	int		i;
	int		width;
	int		height;

	height = 0;
	while (map[height] != NULL)
		height++;
	width = ft_strlen(map[0]);
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 2] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < width - 1)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
