/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:39:29 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/06 09:39:31 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(t_game *game)
{
	free_textures(game);
	if (game->win_ptr && game->mlx_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free_map(&game->map);
	ft_printf(GREEN SUCCESS_EMOJI " Game closed successfully.\n" RESET);
	game->mlx_ptr = NULL;
	exit(EXIT_SUCCESS);
}

void	init_game(t_game *game)
{
	ft_printf(INFO_EMOJI " Initializing game...\n" RESET);
	game->moves = 0;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		free_map(&game->map);
		error_and_exit("Failed to initialize MiniLibX.");
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	if (!game->win_ptr)
	{
		close_game(game);
		error_and_exit("Failed to create game window.");
	}
	load_textures(game);
	ft_printf(GREEN SUCCESS_EMOJI " Game initialized successfully.\n" RESET);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf(RED ERROR_EMOJI " Usage: ./so_long <map_file.ber>\n" RESET);
		return (EXIT_FAILURE);
	}
	game.map.player_count = 0;
	game.map.exit_count = 0;
	game.map.collectibles = 0;
	game.map.map_data = NULL;
	parse_map(&game.map, argv[1]);
	init_game(&game);
	render_game(&game);
	mlx_key_hook(game.win_ptr, handle_keypress, &game);
	mlx_hook(game.win_ptr, 17, 0, (int (*)())close_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
