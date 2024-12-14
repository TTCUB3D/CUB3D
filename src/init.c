/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:32:34 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/14 11:20:43 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	game->textures = NULL;
	game->map = NULL;
	game->map_2d = NULL;
}

void	init_textures_lines(t_game *game)
{
	game->textures->no_line = NULL;
	game->textures->so_line = NULL;
	game->textures->we_line = NULL;
	game->textures->ea_line = NULL;
	game->textures->no_data = NULL;
	game->textures->so_data = NULL;
	game->textures->ea_data = NULL;
	game->textures->we_data = NULL;
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


