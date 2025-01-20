/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:44:11 by danielda          #+#    #+#             */
/*   Updated: 2025/01/20 16:50:39 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_player_x(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'p')
				return (x);
			x++;
		}
	y++;
	}
	return (-1);
}

int	find_player_y(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'p')
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}
