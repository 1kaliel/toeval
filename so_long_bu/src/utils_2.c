/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:07:55 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/30 19:07:56 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_transparent_row(t_game *game, t_image_data *img_data,
		t_render_data *r_data)
{
	int				x;
	int				pixel_offset;
	unsigned int	color;

	x = 0;
	while (x < TILE_SIZE)
	{
		pixel_offset = (r_data->y * img_data->ll) + (x * (img_data->bpp / 8));
		color = *(unsigned int *)(img_data->pixel_data + pixel_offset);
		if (color != 0x000000)
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, r_data->draw_x + x,
				r_data->draw_y + r_data->y, color);
		x++;
	}
}
