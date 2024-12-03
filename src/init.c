/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:32:34 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/03 11:57:13 by tursescu         ###   ########.fr       */
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

void window_init(t_game *game)
{
	size_t	window_width;
	size_t	window_height;
	size_t	map_width;
	size_t	map_height;

	get_map_dimensions(game->map, &map_width, &map_height);
	window_height = map_height;
	window_width = map_width;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, window_width, window_height, "cub3D");
	
}