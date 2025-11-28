/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:27:39 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/28 16:37:04 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../mylibft/get_next_line.h"
# include "../mylibft/libft.h"
# include "../mylibft/printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

/* Event MLX */
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define DESTROY_NOTIFY 17

/* Map items */
# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

/* Sprites */
typedef struct s_img
{
	void	*img;
	int		line_len;
	int		width;
	int		height;
}			t_img;

/* Pos */
typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

/* Map */
typedef struct s_map
{
	char	**grid;
	char	**grid_cpy;
	int		width;
	int		height;
	int		collectibles;
	int		exits;
	int		players;
	t_pos	player_pos;
	t_pos	exit_pos;
}			t_map;

/* Game */
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
}			t_game;

/* === PARSING === */
/* map_parser.c */
int			parse_map(t_game *game, char *filename);
char		**read_map_file(int fd);

/* map_validation.c */
int			validate_map(t_game *game);

/* path_checker.c */
int			check_valid_path(t_game *game);
void		free_grid(char **grid, int height);

/* === GRAPHICS === */
/* init_window.c */
int			init_mlx(t_game *game);

/* render.c */
void		render_map(t_game *game);

/* === GAME === */
/* movement.c */
void		move_player(t_game *game, int dx, int dy);
int			can_move(t_game *game, int new_x, int new_y);
void		update_player_position(t_game *game, int new_x, int new_y);

/* events.c */
int			handle_keypress(int keycode, t_game *game);
int			handle_close(t_game *game);
void		free_map(t_game *game);

#endif