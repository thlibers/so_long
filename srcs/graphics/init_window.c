/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:45:25 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/19 17:47:36 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_img	*load_xpm(t_game *game, char *path)
{
	t_img	*tex;

	tex = malloc(sizeof(*tex));
	if (!tex)
		return (NULL);
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img)
	{
		free(tex);
		return (NULL);
	}
	return (tex);
}

int	load_sprites(t_game *game)
{
	game->player = NULL;
	game->wall = NULL;
	game->empty = NULL;
	game->collectible = NULL;
	game->exit = NULL;
	game->player = load_xpm(game, "textures/player.xpm");
	if (!game->player)
		return (0);
	game->wall = load_xpm(game, "textures/wall.xpm");
	if (!game->wall)
		return (0);
	game->empty = load_xpm(game, "textures/empty.xpm");
	if (!game->empty)
		return (0);
	game->collectible = load_xpm(game, "textures/collectible.xpm");
	if (!game->collectible)
		return (0);
	game->exit = load_xpm(game, "textures/exit.xpm");
	if (!game->exit)
		return (0);
	return (1);
}

int	init_mlx(t_game *game)
{
	int	window_width;
	int	window_height;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error : mlx is not initialized.\n");
		return (0);
	}
	window_width = game->map.width * TILE_SIZE;
	window_height = game->map.height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, window_width, window_height,
			"so_long");
	if (!game->win)
		return (0);
	if (!load_sprites(game))
	{
		ft_printf("Error : sprites cannot be loaded.\n");
		return (0);
	}
	return (1);
}
