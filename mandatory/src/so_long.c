/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:11:45 by danielda          #+#    #+#             */
/*   Updated: 2025/01/13 13:51:04 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//void	map_initializer(t_map *map, char **av)

// #include <mlx.h>
#include "../inc/so_long.h"
#include <stdlib.h>

// #define WINDOW_WIDTH 900
// #define WINDOW_HEIGHT 300

void	window_mlx(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	while (1);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}

int	main(argc, argv)
{
}
