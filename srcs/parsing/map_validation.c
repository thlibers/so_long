/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:07:11 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/14 15:10:06 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_walls(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->map.grid)
		return (ft_printf("Invalid map : grid doesn't exist\n"), 0);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width && (y == 0 || y == game->map.height - 1))
		{
			if (game->map.grid[y][x] != WALL)
				return (ft_printf("invalid map : border is not walls\n"), 0);
			x++;
		}
		if (game->map.grid[y][0] != WALL
			|| game->map.grid[y][game->map.width - 1] != WALL)
			return (ft_printf("invalid map : border is not walls\n"), 0);
		y++;
	}
	return (1);
}

int	check_elements(t_game *game)
{
	int		x;
	int		y;
	char	c;

	if (!game || !game->map.grid)
		return (ft_printf("Invalid map : grid doesn't exist\n"), 0);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			c = game->map.grid[y][x];
			if (c != WALL && c != EMPTY && c != COLLECTIBLE && c != EXIT
				&& c != PLAYER)
				return (ft_printf("Invalid map : unknown character\n"), 0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_at_least_one(t_game *game)
{
	if (!game)
		return (ft_printf("Invalid map : game is NULL\n"), 0);
	if (game->map.players != 1)
		return (ft_printf("Invalid map : 1 player required\n"), 0);
	if (game->map.collectibles < 1)
		return (ft_printf("Invalid map : at least one collectible\n"), 0);
	if (game->map.exits != 1)
		return (ft_printf("Invalid map : 1 exit required\n"), 0);
	return (1);
}

int	check_rectangular(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->map.grid)
		return (ft_printf("invalid map : grid doesn't exist\n"), 0);
	x = game->map.width;
	if (x <= 0 || game->map.height <= 0)
		return (ft_printf("invalid map : incorrect dimensions\n"), 0);
	y = 0;
	while (y < game->map.height)
	{
		if ((int)ft_strlen(game->map.grid[y]) != x)
			return (ft_printf("invalid map : the map is not rectangular\n"), 0);
		y++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!game)
		return (0);
	if (!check_walls(game))
		return (0);
	if (!check_elements(game))
		return (0);
	if (!check_at_least_one(game))
		return (0);
	if (!check_rectangular(game))
		return (0);
	return (1);
}
