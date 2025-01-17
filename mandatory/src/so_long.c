/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:11:45 by danielda          #+#    #+#             */
/*   Updated: 2025/01/17 19:02:31 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include "../inc/so_long.h"
#include <stdlib.h>
#include <stdio.h>

//  #define WINDOW_WIDTH 900
//  #define WINDOW_HEIGHT 300

void	window_mlx(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "My first window!");
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("Error\nUsage: ./so_long <map.ber>\n");
		return (1);
	}
	//map = print_map_term();
	if (//ft_init_game(&data, argv[1]) != 0)
	{
		ft_exit_game(&data);
		return (1);
	}
	mlx_loop_hook(data.mlx_ptr, &//handle_no_event, &data);
	mlx_hook(data.win_ptr, keypress, 1l << 0, &//ft_handle_movement, &data);
	mlx_loop(data.mlx_ptr);
	//ft_cleanup(&data);
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

void	window_inf(void)
{
}
