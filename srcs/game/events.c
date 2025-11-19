/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:58:54 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/19 18:52:26 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (game->game_over)
		return (0);
	if (keycode == KEY_ESC)
		handle_close(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	return (0);
}

static void	free_map(t_game *game)
{
	int	i;

	if (game->map.grid)
	{
		i = 0;
		while (i < game->map.height)
			free(game->map.grid[i++]);
		free(game->map.grid);
	}
	if (game->player)
		free(game->player);
	if (game->exit)
		free(game->exit);
	if (game->collectible)
		free(game->collectible);
	if (game->wall)
		free(game->wall);
	if (game->empty)
		free(game->empty);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	handle_close(t_game *game)
{
	if (game->player && game->player->img)
		mlx_destroy_image(game->mlx, game->player->img);
	if (game->exit && game->exit->img)
		mlx_destroy_image(game->mlx, game->exit->img);
	if (game->collectible && game->collectible->img)
		mlx_destroy_image(game->mlx, game->collectible->img);
	if (game->wall && game->wall->img)
		mlx_destroy_image(game->mlx, game->wall->img);
	if (game->empty && game->empty->img)
		mlx_destroy_image(game->mlx, game->empty->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	exit(0);
	return (0);
}
