/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:05:41 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/30 16:05:43 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Standard Libraries */
# include "ft_printf/includes/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>

/* Tile Dimensions */
# define TILE_SIZE 32

/* File Paths for Textures */
# define WALL_TEXTURE "textures/wall.xpm"
# define FLOOR_TEXTURE "textures/floor.xpm"
# define PLAYER_TEXTURE "textures/player.xpm"
# define EXIT_TEXTURE "textures/exit.xpm"
# define COLLECTIBLE_TEXTURE "textures/collectible.xpm"

/* Map Elements */
# define WALL_CHAR '1'
# define FLOOR_CHAR '0'
# define PLAYER_CHAR 'P'
# define EXIT_CHAR 'E'
# define COLLECTIBLE_CHAR 'C'

/* Key Codes */
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

/* Console Colors and Emojis */
# define RESET "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define ERROR_EMOJI "❌"
# define SUCCESS_EMOJI "✅"
# define INFO_EMOJI "ℹ️"

/* Structures */

/* Image Data Structure */
typedef struct s_image
{
	void	*img_ptr;
	int		width;
	int		height;
}			t_image;

/* Map Data Structure */
typedef struct s_map
{
	char	**map_data;
	int		width;
	int		height;
	int		collectibles;
	int		exit_count;
	int		player_count;
	int		player_x;
	int		player_y;
}			t_map;

/* Game Data Structure */
typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	int		moves;
	t_image	wall;
	t_image	floor;
	t_image	player;
	t_image	exit;
	t_image	collectible;
}			t_game;

typedef struct s_image_data
{
	char	*pixel_data;
	int		bpp;
	int		ll;
	int		endian;
}			t_image_data;

typedef struct s_pixel_data
{
	char	*pixel_data;
	int		offset;
	int		x;
	int		y;
}			t_pixel_data;

typedef struct s_render_data
{
	int	draw_x;
	int	draw_y;
	int	y;
}			t_render_data;

/* Function Prototypes */
void		parse_map(t_map *map, const char *file);
void		render_game(t_game *game);
void		load_textures(t_game *game);
void		error_and_exit(const char *msg);
int			handle_keypress(int keycode, t_game *game);
void		close_game(t_game *game);

// parse
void		parse_line(t_map *map, char *line, int i);
void		parse_map(t_map *map, const char *file);

// map
void		check_rectangular(t_map *map);
void		check_walls(t_map *map);
void		validate_map(t_map *map);
void		validate_components(t_map *map);

// utils
int			count_lines(const char *file);
void		trim_line(char *line);
void		render_pixel_if_visible(t_game *game, t_pixel_data *data);

// kill
void		free_map(t_map *map);
void		free_textures(t_game *game);

#endif
