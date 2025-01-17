/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:15:14 by danielda          #+#    #+#             */
/*   Updated: 2025/01/17 16:34:28 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_map_term(void)
{
	char	map;

	map = read_map(argv[1]);
	if (!map)
	{
		printf("Error: Failed to load map\n");
		return (1);
	}
	print_map(map);
	if (!validate_map(map))
	{
		printf("Error: Invalid map\n");
		return (1);
	}
	return (0);
}

void	print_map(char **map)
{
	int	i;

	if (!map)
	{
		printf("Mapa inválido ou não carregado!\n");
		return ;
	}
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
