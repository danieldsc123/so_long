/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:11:45 by danielda          #+#    #+#             */
/*   Updated: 2025/02/14 21:31:25 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>

void	initialize_game(t_game *game, char *map_path)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(2, "Error: Failed to initialize MLX\n", 32);
		free(game->mlx);
		exit(1);
	}
	game->map = read_map(map_path);
	game->player_x = find_player_x(game->map);
	game->player_y = find_player_y(game->map);
	game->collectibles = count_chars(game->map, 'C');
	game->map_width = get_map_width(game->map);
	game->map_height = get_map_height(game->map);
	if (!validate_map(game) || !is_valid_extension(map_path))
	{
		write(2, "Error: Invalid map\n", 19);
		free(game->map);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, (game->map_width * TILE_SIZE),
			(game->map_height * TILE_SIZE), "so_long");
	load_textures(game);
}

int	handle_exit(void *param)
{
	exit_game((t_game *)param);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc((sizeof(t_game) * 1));
	game->steps = 0;
	if (!game)
		return (1);
	if (argc != 2)
	{
		write(2, "Error\nUsage: ./so_long <map.ber>\n", 33);
		free(game);
		return (1);
	}
	parse_map(argc, argv);
	initialize_game(game, argv[1]);
	init_images(game);
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
	mlx_hook(game->win, 17, 0, handle_exit, game);
	mlx_loop(game->mlx);
	exit_game(game);
	// free_game(game);
	return (0);
}

// void	free_game(t_game *game)
// {
// 	if (!game)
// 		return ;
// 	if (game->map)
// 		free_map(game->map);
// 	// free(game);
// }

// void	free_map(char **map)
// {
// 	int	i;

// 	if (!map)
// 		return ;
// 	i = 0;
// 	while (map[i])
// 	{
// 		free(map[i]);
// 		i++;
// 	}
// 	free(map);
// }
