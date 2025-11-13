/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:30:49 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/13 17:04:42 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void free_grid(char **grid, int height)
{
	int i;

	if(!grid)
		return ;
	i = 0;
	while(i < height && grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

static char **dup_grid(char **grid, int height)
{
	char **dup;
	int i;

	if (!grid || height <= 0)
		return (NULL);
	dup = malloc(sizeof(char *) * (height + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < height)
	{
		dup[i] = ft_strdup(grid[i]);
		if(!dup[i])
		{
			while(--i >= 0)
				free(dup[i]);
			free(dup);
			return (NULL);
		}
		i++;
	}
	dup[height] = NULL;
	return (dup);
}

void	flood_fill(char **map, t_pos pos, t_pos size)
{
	if (!map)
		return ;
	if (pos.x < 0 || pos.y < 0 || pos.x >= size.x || pos.y >= size.y)
		return ;
	if (map[pos.y][pos.x] == WALL || map[pos.y][pos.x] == 'V')
		return ;
	map[pos.y][pos.x] = 'V';
	flood_fill(map, (t_pos){pos.y + 1, pos.x}, size);
	flood_fill(map, (t_pos){pos.y - 1, pos.x}, size);
	flood_fill(map, (t_pos){pos.y, pos.x + 1}, size);
	flood_fill(map, (t_pos){pos.y, pos.x - 1}, size);
}

int		check_valid_path(t_game *game)
{
	char **grid;
	t_pos size;
	int x;
	int y;

	if(!game || !game->map.grid)
		return (ft_printf("Path check error: game or map is NULL\n"), 0);
	size.x = game->map.width;
	size.y = game->map.height;
	if (game->map.player_pos.x < 0 || game->map.player_pos.y < 0
        || game->map.player_pos.x >= size.x || game->map.player_pos.y >= size.y)
	grid = dup_grid(game->map.grid, game->map.height);
	if (!grid)
		return (ft_printf("Path check error (memory)\n"), 0);
	flood_fill(grid, game->map.player_pos, size);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == COLLECTIBLE || grid[y][x] == EXIT)
				return (ft_printf("Invalid map : unreachable collectible or exit\n"), 0);
			x++;
		}
		y++;
	}
	return (free_grid(grid, game->map.height), 1);
}
