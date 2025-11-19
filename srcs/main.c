/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:40:20 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/19 18:52:08 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static void	free_grid(char **grid)
// {
//     int i;

//     if (!grid)
//         return ;
//     i = 0;
//     while (grid[i])
//     {
//         free(grid[i]);
//         i++;
//     }
//     free(grid);
// }

/* ========== ouvrir une fenetre ========== */

// int main(void)
// {
//     void *mlx;
//     void *mlx_win;

//     mlx = mlx_init();
//     if (!mlx)
//     {
//         ft_putendl_fd("Error: mlx_init failed", 2);
//         return (1);
//     }
//     mlx_win = mlx_new_window(mlx, 480, 360, "Hello world!");
//     if (!mlx_win)
//     {
//         ft_putendl_fd("Error: mlx_new_window failed", 2);
//         return (1);
//     }
//     mlx_loop(mlx);
//     return (0);
// }

/* ========== afficher le fichier map et verifier le parsing ========== */

// int	main(int argc, char **argv)
// {
// 	(void)argc;
//     char	*path = argv[1];
//     t_game		game = {0};

//     if (!parse_map(&game, (char *)path))
//     {
//         return (1);
//     }
//     if (!validate_map(&game))
//     {
//         free_grid(game.map.grid);
//         return (1);
//     }
//     if (!check_valid_path(&game))
//     {
//         free_grid(game.map.grid);
//         return (1);
//     }
// 	int y = 0;
// 	ft_printf("\n");
// 	while(game.map.grid[y])
// 	{
// 		printf("%s\n", game.map.grid[y]);
// 		y++;
// 	}
// 	ft_printf("\n");
//     ft_printf("Map loaded and valid: %dx%d, collectibles=%d\n",
//         game.map.width, game.map.height, game.map.collectibles);
//     free_grid(game.map.grid);
//     return (0);
// }

/* ========== afficher la map dans la fenetre ========== */

// int	main(int argc, char **argv)
// {
// 	(void)argc;
//     char	*path = argv[1];
//     t_game		game = {0};

//     if (!parse_map(&game, (char *)path))
//         return (1);
//     if (!validate_map(&game))
//     {
//         free_grid(game.map.grid);
//         return (1);
//     }
//     if (!check_valid_path(&game))
//     {
//         free_grid(game.map.grid);
//         return (1);
//     }
//     init_mlx(&game);
// 	render_map(&game);
// 	mlx_loop(game.mlx);
//     free_grid(game.map.grid);
//     return (0);
// }

/* ========== afficher le jeu avec les commandes ========== */

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_printf("Too many files.\n"), 0);
	ft_memset(&game, 0, sizeof(t_game));
	if (!parse_map(&game, av[1]) || !validate_map(&game)
		|| !check_valid_path(&game))
		return (ft_printf("Invalid map :\n"), 0);
	if (!init_mlx(&game))
		return (ft_printf("Initialization failed :\n"), 0);
	render_map(&game);
	mlx_hook(game.win, KEY_PRESS, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
