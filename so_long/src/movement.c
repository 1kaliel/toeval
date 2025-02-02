/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:40:11 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/06 09:40:13 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_tile_interaction(t_game *game, char tile, int x, int y)
{
	if (tile == 'C')
	{
		game->map.collectibles--;
		game->map.map_data[y][x] = '0';
		ft_printf(YELLOW INFO_EMOJI " Collected a gear! %d left\n" RESET,
			game->map.collectibles);
	}
	else if (tile == 'E')
	{
		if (game->map.collectibles > 0)
		{
			ft_printf(RED ERROR_EMOJI " You must collect stuff first!\n" RESET);
			return (0);
		}
		ft_printf(GREEN SUCCESS_EMOJI " You have completed the game.\n" RESET);
		close_game(game);
	}
	return (1);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	char	current_tile;

	current_tile = game->map.map_data[new_y][new_x];
	if (current_tile == '1')
		return ;
	if (!handle_tile_interaction(game, current_tile, new_x, new_y))
		return ;
	game->map.map_data[game->map.player_y][game->map.player_x] = '0';
	game->map.map_data[new_y][new_x] = 'P';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	game->moves++;
	ft_printf(BLUE INFO_EMOJI " Moves: %d\n" RESET, game->moves);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		move_player(game, game->map.player_x, game->map.player_y - 1);
	else if (keycode == KEY_S)
		move_player(game, game->map.player_x, game->map.player_y + 1);
	else if (keycode == KEY_A)
		move_player(game, game->map.player_x - 1, game->map.player_y);
	else if (keycode == KEY_D)
		move_player(game, game->map.player_x + 1, game->map.player_y);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	render_game(game);
	return (0);
}
