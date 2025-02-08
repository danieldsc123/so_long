/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:52:24 by danielda          #+#    #+#             */
/*   Updated: 2025/02/08 20:19:28 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

#include "../inc/so_long.h"

// Função flood fill para percorrer o mapa
int check_visit_maps(t_game *game, char **maps, int x, int y)
{
    // Verifica se a posição está fora dos limites ou é uma parede
    if (x < 0 || y < 0 || !maps[y] || x >= (int)ft_strlen(maps[y]) || maps[y][x] == '1' || maps[y][x] == 'V')
        return (0);
    
    // Marca o espaço como visitado
    if (maps[y][x] == 'C')  // Se encontrar um coletável, diminui a contagem
    {
        game->collectibles--;
        maps[y][x] = 'V'; // Marca como visitado
    }
    else if (maps[y][x] == '0')  // Se for um espaço vazio, apenas marca como visitado
    {
        maps[y][x] = 'V';
    }

    // Chama recursivamente as direções para as próximas células
    check_visit_maps(game, maps, x + 1, y);
    check_visit_maps(game, maps, x - 1, y);
    check_visit_maps(game, maps, x, y + 1);
    check_visit_maps(game, maps, x, y - 1);

    return (1);
}

// Função que verifica se o mapa tem um caminho válido
int is_valid_path(t_game *game)
{
    char    **map_copy;
    int     y;
    int     x;

    // Copia o mapa para não modificar o original
    map_copy = copy_map(game->map);
    if (!map_copy)
        return (0);

    // Chama a função de flood fill a partir da posição do jogador
    check_visit_maps(game, map_copy, game->player_x, game->player_y);

    // Verifica se ainda existem coletáveis ou se a saída não foi atingida
    y = 0;
    while (map_copy[y])
    {
        x = 0;
        while (map_copy[y][x])
        {
            if (game->map[y][x] == 'C' || game->map[y][x] == 'E')
            {
                if (map_copy[y][x] != 'V')  // Se algum coletável ou a saída não foi visitado
                {
                    free_map(map_copy, get_map_height(game->map));
                    return (0);
                }
            }
            x++;
        }
        y++;
    }
    free_map(map_copy, get_map_height(game->map));
    return (1);
}
