/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:32:30 by danielda          #+#    #+#             */
/*   Updated: 2025/02/13 02:12:46 by danielda         ###   ########.fr       */
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

int	is_valid_map(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL) // Percorre cada linha da matriz
	{
		col = 0;
		while (map[row][col] != '\0') // Percorre cada caractere da linha
		{
			if (map[row][col] != '1' && map[row][col] != '0' && map[row][col] != 'P'
				&& map[row][col] != 'C' && map[row][col] != 'E' && map[row][col] != '\n')
			{
				printf("Caractere inválido encontrado: %c\n", map[row][col]);
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}


int	is_map_rectangular(char **map)
{
	int		i;
	size_t	length;

	i = 0;
	length = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != length)
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
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

// char	allocate_map(void)
// {
// 	return (malloc(sizeof(char *) * 1024));
// }
