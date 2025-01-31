/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:08:21 by danielda          #+#    #+#             */
/*   Updated: 2025/01/31 18:04:25 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../inc/so_long.h"

char	**read_map(const char *file)
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
		return (NULL);
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

// #include <fcntl.h>
// #include <unistd.h>
// #include <stdlib.h>

// char	*get_next_line(int fd);

// void	free_map(char **map, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		free(map[i]);
// 		i++;
// 	}
// 	free(map);
// }

// char	**read_map(const char *file)
// {
// 	int		fd;
// 	int		i;
// 	int		line_count;
// 	char	*line;
// 	char	**map;

// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (NULL);
// 	line_count = 0;
// 	while (get_next_line(fd))
// 	{
// 		line_count++;
// 	}
// 	close(fd);
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (NULL);
// 	map = malloc(sizeof(char *) * (line_count + 1));
// 	if (!map)
// 		return (NULL);
// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		map[i] = line;
// 		i++;
// 		line = get_next_line(fd);
// 	}
// 	map[i] = NULL;
// 	close(fd);
// 	return (map);
// }
