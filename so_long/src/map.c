/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:39:49 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/06 09:39:51 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_data[i])
	{
		if ((int)ft_strlen(map->map_data[i]) != map->width)
			error_and_exit("Map is not rectangular.");
		i++;
	}
}

void	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		if (i == 0 || i == map->height - 1)
		{
			j = 0;
			while (j < map->width)
			{
				if (map->map_data[i][j] != '1')
					error_and_exit("Map boundaries must be walls.");
				j++;
			}
		}
		else
		{
			if (map->map_data[i][0] != '1' || map->map_data[i][map->width
				- 1] != '1')
				error_and_exit("Map must be surrounded by walls.");
		}
		i++;
	}
	ft_printf(GREEN SUCCESS_EMOJI " Walls validated successfully.\n" RESET);
}

void	validate_map(t_map *map)
{
	check_rectangular(map);
	check_walls(map);
	validate_components(map);
}

void	validate_components(t_map *map)
{
	if (map->player_count != 1)
		error_and_exit("Map must have exactly one player (P).");
	if (map->exit_count != 1)
		error_and_exit("Map must have exactly one exit (E).");
	if (map->collectibles < 1)
		error_and_exit("Map must have at least one collectible (C).");
}
