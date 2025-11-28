/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:59:01 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/28 14:31:21 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map.player_pos.x + dx;
	new_y = game->map.player_pos.y + dy;
	if (can_move(game, new_x, new_y))
	{
		game->moves++;
		update_player_position(game, new_x, new_y);
		ft_printf("Moves : %d\n", game->moves);
	}
}

int	can_move(t_game *game, int new_x, int new_y)
{
	char	tile;

	if (new_x < 0 || new_y < 0 || new_x >= game->map.width
		|| new_y >= game->map.height)
		return (0);
	tile = game->map.grid[new_y][new_x];
	if (tile == WALL)
		return (0);
	if (tile == EXIT && game->collected < game->map.collectibles)
		return (0);
	if (tile == EXIT && game->collected == game->map.collectibles)
	{
		game->moves++;
		ft_printf("✨ Congratulation ! You won ! 🎉\n");
		ft_printf("Total moves : %d\n", game->moves);
		game->game_over = 1;
		handle_close(game);
	}
	return (1);
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	int	p_pos_x;
	int	p_pos_y;

	p_pos_x = game->map.player_pos.x;
	p_pos_y = game->map.player_pos.y;
	if (game->map.grid[new_y][new_x] == COLLECTIBLE)
	{
		game->collected++;
		game->map.grid[new_y][new_x] = EMPTY;
	}
	game->map.grid[p_pos_y][p_pos_x] = EMPTY;
	game->map.player_pos.x = new_x;
	game->map.player_pos.y = new_y;
	game->map.grid[new_y][new_x] = PLAYER;
	render_map(game);
}
