/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:11:45 by danielda          #+#    #+#             */
/*   Updated: 2025/01/31 17:31:01 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include "../inc/so_long.h"
#include <stdlib.h>
//#include <stdio.h>

//  #define WINDOW_WIDTH 900
//  #define WINDOW_HEIGHT 300

void	initialize_game(t_game *game, char *map_path)
{
	int	map_width;
	int	map_height;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(2, "Error: Failed to initialize MLX\n", 32);
		exit(1);
	}
	game->map = read_map(map_path);
	if (validate_map(game->map) != 0)
	{
		write(2, "Error: Invalid map\n", 19);
		exit(1);
	}
	game->player_x = find_player_x(game->map);
	game->player_y = find_player_y(game->map);
	game->collectibles = count_chars(game->map, 'C');
	map_width = get_map_width(game->map);
	map_height = get_map_height(game->map);
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "so_long");
	load_textures(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc((sizeof(t_game) * 1));
	if (argc != 2)
	{
		printf("error");
		write(2, "Error\nUsage: ./so_long <map.ber>\n", 33);
		return (1);
	}
	initialize_game(game, argv[1]);
	init_images(game);
	render_map(game);
	mlx_key_hook(game->win, handle_key, game);
	mlx_loop(game->mlx);
	exit_game(game);
	return (0);
}	
