/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:08:21 by danielda          #+#    #+#             */
/*   Updated: 2025/02/13 22:44:50 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../inc/so_long.h"

// char	**read_map(const char *file)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;
// 	char	**map;

// 	i = 0;
// 	if (!is_valid_extension(file))
// 		return (write(1, "Invalid file extension\n", 23), NULL);
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (write(1, "Error opening file\n", 19), NULL);
// 	map = allocate_map();
// 	if (!map)
// 		return (close(fd), write(1, "Memory allocation error\n", 24), NULL);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		if (!is_valid_line(line))
// 			return (write(1, "Invalid map line\n", 18)
// 				, close(fd), free(map), NULL);
// 		map[i++] = line;
// 	}
// 	map[i] = NULL;
// 	close(fd);
// 	if (!is_map_rectangular(map) || !is_map_closed(map))
// 		return (write(1, "Invalid map structure\n", 23), free(map), NULL);
// 	return (map);
// }

char	**read_map(char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * 1024);
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**parse_map(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
	{
		write(1, "Error\nInvalid number of arguments\n", 35);
		exit(1);
	}
	if (is_valid_extension(argv[1]) != 1)
	{
		write(1, "Error\nInvalid file extension\n", 29);
		exit(1);
	}
	map = read_map(argv[1]);
	if (!map)
	{
		write(1, "Error\nInvalid map\n", 19);
		exit(1);
	}
	return (map);
}

int	execute_map_validations(t_game *game)
{
	if (!is_map_rectangular(game->map))
	{
		write(1, "Error\nInvalid map structure\n", 29);
		return (0);
	}
	if (!is_map_closed(game->map))
	{
		write(1, "Error\nInvalid map wall\n", 28);
		return (0);
	}
	if (!components_check_maps(game))
	{
		write(1, "Error\nInvalid duplicates\n", 28);
		return (0);
	}
	return (1);
}
