/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:40:37 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/06 09:40:38 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_exit(const char *msg)
{
	ft_printf(RED ERROR_EMOJI " Error: %s\n" RESET, msg);
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map->map_data)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->map_data[i]);
		i++;
	}
	free(map->map_data);
	map->map_data = NULL;
}

int	count_lines(const char *file)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_and_exit("Failed to open map file.");
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	trim_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'
			|| line[len - 1] == '\t'))
	{
		line[len - 1] = '\0';
		len--;
	}
}

void	render_pixel_if_visible(t_game *game, t_pixel_data *data)
{
	unsigned int	color;

	color = *(unsigned int *)(data->pixel_data + data->offset);
	if (color != 0x000000)
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, data->x, data->y, color);
}
