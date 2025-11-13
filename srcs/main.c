/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:40:20 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/13 18:19:54 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* ==========afficher une fenetre========== */

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

/* ==========afficher la map et verifier le parsing========== */

// #include "../includes/so_long.h"

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

// int	main(int argc, char **argv)
// {
//     const char	*path = (argc > 1) ? argv[1] : "map.ber";
//     t_game		game = {0};

//     if (!parse_map(&game, (char *)path))
//     {
//         ft_printf("Error: parse_map failed\n");
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
// 	while(game.map.grid[y])
// 	{
// 		printf("%s\n", game.map.grid[y]);
// 		y++;
// 	}

//     ft_printf("Map loaded and valid: %dx%d, collectibles=%d\n",
//         game.map.width, game.map.height, game.map.collectibles);
//     free_grid(game.map.grid);
//     return (0);
// }