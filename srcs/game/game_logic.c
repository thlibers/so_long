/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:58:58 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/19 17:53:10 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	collect_item(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == COLLECTIBLE)
	{
		game->collected++;
		game->map.grid[y][x] = EMPTY;
		ft_printf("Collectible collected !");
	}
}

void	check_win(t_game *game)
{
	int	p_pos_x;
	int	p_pos_y;

	p_pos_x = game->map.player_pos.x;
	p_pos_y = game->map.player_pos.y;
	if (game->collected == game->map.collectibles)
	{
		if (game->map.grid[p_pos_y][p_pos_x] == EXIT)
		{
			ft_printf("Congratulation ! You won !\n");
			ft_printf("Total moves : %d\n", game->moves);
			game->game_over = 1;
			handle_close(game);
		}
	}
}
