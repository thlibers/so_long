/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:45:29 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/17 13:58:31 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void render_tile(t_game *game, int x, int y)
{
	t_img *tex;
	char c;

	if(!game || game->map.grid)
		return ;
	c = game->map.grid[y][x];
	tex = NULL;
	if (c == WALL)
		tex = game->wall;
	else if (c == EMPTY)
		tex = game->empty;
	else if (c == PLAYER)
		tex = game->player;
	else if (c == EXIT)
		tex = game->exit;
	else if (c == COLLECTIBLE)
		tex = game->collectible;
	if (tex)
		put_image(game, tex, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_moves(t_game *game)
{
	char *move_str;
	char *moves;

	if(!game || !game->mlx || !game->win)
		return ;
	move_str = ft_itoa(game->moves);
	if(!move_str)
		return ;
	moves = ft_strjoin("Moves : ", move_str);
	free(move_str);
	if(!moves)
		return ;
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, moves);
	free(moves);
}

void render_map(t_game *game)
{
	int x;
	int y;

	if (!game || !game->map.grid)
		return ;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	render_moves(game);
}