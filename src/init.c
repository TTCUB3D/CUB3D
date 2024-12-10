/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:32:34 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/10 16:23:27 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	game->textures->no_line = NULL;
	game->textures->so_line = NULL;
	game->textures->we_line = NULL;
	game->textures->ea_line = NULL;
	game->map = NULL;
	game->map_2d = NULL;
}

void	init_key_states(bool **key_states)
{
	int	i;

	i = 0;
	*key_states = malloc(MAX_KEY_CODE * sizeof(bool *));
	if (!(*key_states))
	{
		perror("Failed to alloc memory for keys_states");
		exit(1);
	}
	while (i < MAX_KEY_CODE)
	{
		(*key_states)[i] = false;
		i++;
	}
	
}

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
