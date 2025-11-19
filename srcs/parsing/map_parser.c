/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:22:18 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/18 15:34:57 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	**new_grid(char **grid, int size, char *line)
{
	char	**newgrid;
	int		i;

	newgrid = malloc(sizeof(char *) * (size + 2));
	if (!newgrid)
		return (NULL);
	i = 0;
	while (i < size)
	{
		newgrid[i] = grid[i];
		i++;
	}
	newgrid[size] = line;
	newgrid[size + 1] = NULL;
	free(grid);
	return (newgrid);
}

char	**read_map_file(char *filename)
{
	int		fd;
	char	*line;
	char	**grid;
	int		size;
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	grid = NULL;
	size = 0;
	while ((line = get_next_line(fd)))
	{
		if (!line)
			break ;
		len = (int)ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		grid = new_grid(grid, size, ft_strdup(line));
		free(line);
		if (!grid)
			return (close(fd), NULL);
		size++;
	}
	return (close(fd), grid);
}

int	get_map_width(char **grid)
{
	if (!grid || !grid[0])
		return (0);
	return ((int)ft_strlen(grid[0]));
}

static void	wich_item(t_game *game, int y, int height, char **grid)
{
	int	x;

	while (y < height)
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == COLLECTIBLE)
				game->map.collectibles++;
			else if (grid[y][x] == EXIT)
			{
				game->map.exits++;
				game->map.exit_pos.x = x;
				game->map.exit_pos.y = y;
			}
			else if (grid[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player_pos.x = x;
				game->map.player_pos.y = y;
			}
			x++;
		}
		y++;
	}
}

int	parse_map(t_game *game, char *filename)
{
	char	**grid;
	int		height;
	int		y;

	grid = read_map_file(filename);
	if (!grid)
	{
		ft_printf("Failed to read map file.\n");
		return (0);
	}
	height = 0;
	while (grid[height])
		height++;
	game->map.grid = grid;
	game->map.height = height;
	game->map.width = get_map_width(grid);
	game->map.collectibles = 0;
	game->map.exits = 0;
	game->map.players = 0;
	y = 0;
	wich_item(game, y, height, grid);
	return (1);
}
