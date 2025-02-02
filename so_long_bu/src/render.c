/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:11:48 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/30 13:11:50 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	resize_image(t_game *game, void **img, int *width, int *height)
{
	void	*new_img;

	new_img = mlx_xpm_file_to_image(game->mlx_ptr, *img, width, height);
	if (!new_img)
		error_and_exit("Failed to resize texture.");
	*img = new_img;
}

void	load_textures(t_game *game)
{
	game->wall.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, WALL_TEXTURE,
			&game->wall.width, &game->wall.height);
	if (!game->wall.img_ptr)
		error_and_exit("Failed to load wall texture.");
	game->floor.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR_TEXTURE,
			&game->floor.width, &game->floor.height);
	if (!game->floor.img_ptr)
		error_and_exit("Failed to load floor texture.");
	game->player.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_TEXTURE,
			&game->player.width, &game->player.height);
	if (!game->player.img_ptr)
		error_and_exit("Failed to load player texture.");
	game->exit.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_TEXTURE,
			&game->exit.width, &game->exit.height);
	if (!game->exit.img_ptr)
		error_and_exit("Failed to load exit texture.");
	game->collectible.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE_TEXTURE, &game->collectible.width,
			&game->collectible.height);
	if (!game->collectible.img_ptr)
		error_and_exit("Failed to load collectible texture.");
}

void	render_with_transparency(t_game *game, void *img, int draw_x,
		int draw_y)
{
	t_image_data	data;
	t_pixel_data	pixel;
	int				x;
	int				y;

	pixel.pixel_data = mlx_get_data_addr(img, &data.bpp, &data.ll,
			&data.endian);
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			pixel.offset = (y * data.ll) + (x * (data.bpp / 8));
			pixel.x = draw_x + x;
			pixel.y = draw_y + y;
			render_pixel_if_visible(game, &pixel);
			x++;
		}
		y++;
	}
}

void	render_tile(t_game *game, char tile, int draw_x, int draw_y)
{
	if (tile == WALL_CHAR)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall.img_ptr, draw_x, draw_y);
	else if (tile == COLLECTIBLE_CHAR)
		render_with_transparency(game, game->collectible.img_ptr, draw_x,
			draw_y);
	else if (tile == EXIT_CHAR)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->exit.img_ptr, draw_x, draw_y);
	else if (tile == PLAYER_CHAR)
		render_with_transparency(game, game->player.img_ptr, draw_x, draw_y);
}

void	render_game(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->floor.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
			tile = game->map.map_data[y][x];
			render_tile(game, tile, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
