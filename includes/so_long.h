/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:27:39 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/13 18:15:42 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../mylibft/get_next_line.h"
#include "../mylibft/printf.h"
#include "../mylibft/libft.h"
#include "../minilibx-linux/mlx.h"

/* Taille des sprites */
# define TILE_SIZE 64

/* Codes de touches */
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

/* Codes d'événements MLX */
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define DESTROY_NOTIFY 17

/* Éléments de la carte */
# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

/* Structure pour les images/sprites */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

/* Structure pour la position */
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

/* Structure pour la carte */
typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exits;
	int		players;
	t_pos	player_pos;
	t_pos	exit_pos;
}	t_map;

/* Structure principale du jeu */
typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	*player;
	t_img	*wall;
	t_img	*empty;
	t_img	*collectible;
	t_img	*exit;
	int		collected;
	int		moves;
	int		game_over;
}	t_game;

/* === PARSING === */
/* map_parser.c */
int		parse_map(t_game *game, char *filename);
char	**read_map_file(char *filename);
int		get_map_width(char **grid);

/* map_validation.c */
int		validate_map(t_game *game);
int		check_walls(t_game *game);
int		check_elements(t_game *game);
int		check_at_least_one(t_game *game);
int		check_rectangular(t_game *game);

/* path_checker.c */
int		check_valid_path(t_game *game);
void	flood_fill(char **map, t_pos pos, t_pos size);

/* === GRAPHICS === */
/* init_mlx.c */
int		init_mlx(t_game *game);
int		load_sprites(t_game *game);
t_img	*load_xpm(t_game *game, char *path);

/* render.c */
void	render_map(t_game *game);
void	render_tile(t_game *game, int x, int y);
void	render_ui(t_game *game);

/* sprites.c */
void	put_image(t_game *game, t_img *img, int x, int y);

/* === GAME === */
/* movement.c */
void	move_player(t_game *game, int dx, int dy);
int		can_move(t_game *game, int new_x, int new_y);
void	update_player_position(t_game *game, int new_x, int new_y);

/* events.c */
int		handle_keypress(int keycode, t_game *game);
int		handle_close(t_game *game);

/* game_logic.c */
void	collect_item(t_game *game, int x, int y);
void	check_win(t_game *game);
void	print_moves(t_game *game);

/* === UTILS === */
/* error.c */
void	error_exit(char *message);
void	print_error(char *message);

/* cleanup.c */
void	cleanup_game(t_game *game);
void	free_map(char **map);
void	destroy_images(t_game *game);

# endif