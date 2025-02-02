/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:12:06 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/30 13:12:08 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_tile(t_map *map, char tile, int x, int y)
{
	if (tile == PLAYER_CHAR)
	{
		map->player_count++;
		ft_printf(YELLOW INFO_EMOJI " Current player count: %d\n" RESET,
			map->player_count);
		if (map->player_count > 1)
			error_and_exit("Map must have exactly one player (P).");
		map->player_x = x;
		map->player_y = y;
	}
	else if (tile == EXIT_CHAR)
	{
		map->exit_count++;
		ft_printf(YELLOW INFO_EMOJI " Found exit at (%d, %d)\n" RESET, y, x);
	}
	else if (tile == COLLECTIBLE_CHAR)
	{
		map->collectibles++;
		ft_printf(YELLOW INFO_EMOJI " Found collectible at (%d, %d)\n" RESET, y,
			x);
	}
	else if (tile != WALL_CHAR && tile != FLOOR_CHAR)
		error_and_exit("Map contains invalid characters.");
}

void	parse_line(t_map *map, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
	{
		parse_tile(map, line[x], x, y);
		x++;
	}
}

void	read_map_line(t_map *map, char *line, int i)
{
	trim_line(line);
	map->map_data[i] = line;
	ft_printf(BLUE INFO_EMOJI " Reading line %d: '%s'\n" RESET, i, line);
	if (i == 0)
		map->width = ft_strlen(line);
	parse_line(map, line, i);
}

void	parse_map(t_map *map, const char *file)
{
	int		fd;
	int		i;
	char	*line;

	map->height = count_lines(file);
	map->map_data = malloc((map->height + 1) * sizeof(char *));
	if (!map->map_data)
		error_and_exit("Failed to allocate memory for map.");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_and_exit("Failed to open map file.");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		read_map_line(map, line, i);
		i++;
		line = get_next_line(fd);
	}
	map->map_data[i] = NULL;
	close(fd);
	ft_printf(GREEN SUCCESS_EMOJI " Final player count: %d\n" RESET,
		map->player_count);
	validate_map(map);
	ft_printf(GREEN SUCCESS_EMOJI " Map parsed successfully.\n" RESET);
}
