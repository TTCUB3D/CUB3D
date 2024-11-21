/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:32:34 by tursescu          #+#    #+#             */
/*   Updated: 2024/11/21 17:21:37 by tursescu         ###   ########.fr       */
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
	game->map = NULL;
	game->just_map = NULL;
	game->textures = NULL;
	game->map_2d = NULL;
}