/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:08:37 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/30 19:08:39 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_textures(t_game *game)
{
	if (!game->mlx_ptr)
		return ;
	if (game->wall.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall.img_ptr);
	if (game->floor.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->floor.img_ptr);
	if (game->player.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.img_ptr);
	if (game->exit.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit.img_ptr);
	if (game->collectible.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->collectible.img_ptr);
}
