/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:32:34 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/03 14:10:41 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures_null(t_textures *textures)
{
	textures->no_line = NULL;
	textures->so_line = NULL;
	textures->we_line = NULL;
	textures->ea_line = NULL;
}

void	init_game(t_game *game)
{
	game->map = NULL;
	game->textures = NULL;
	game->map_2d = NULL;
}

// void	window_init(t_game *game)
// {
// 	size_t	window_width;
// 	size_t	window_height;

// 	window_height = game->height * TILE_SIZE;
// 	window_width = game->width * TILE_SIZE;
// 	printf("here\n");
// 	game->mlx = mlx_init();
// 	if (!game->mlx)
// 	{
// 		err("Error initializing MLX");
// 		propper_exit(game);
// 	}
// 	game->win = mlx_new_window(game->mlx, window_width, window_height, "cub3D");
// 	if (!game->win)
// 	{
// 		err("Error initializing WIN");
// 		propper_exit(game);	
// 	}
// 	textrue_init(game, game->textures);
// 	render_map(game);
// 	mlx_loop(game->mlx);
// }

// void	textrue_init(t_game *game, t_textures *textures)
// {
// 	int	i;
// 	int width;
// 	int	height;

// 	game->img[0] = mlx_xpm_file_to_image(game->mlx, textures->no_line, &width, &height);
// 	game->img[1] = mlx_xpm_file_to_image(game->mlx, textures->so_line, &width, &height);
// 	game->img[2] = mlx_xpm_file_to_image(game->mlx, textures->we_line, &width, &height);
// 	game->img[3] = mlx_xpm_file_to_image(game->mlx, textures->ea_line, &width, &height);
// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (!game->img[i])
// 		{
// 			err("Error initializing textures");
// 			propper_exit(game);
// 		}
// 		i++;
// 	}	
// }
