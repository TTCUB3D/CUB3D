/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:14:09 by tursescu          #+#    #+#             */
/*   Updated: 2024/11/21 16:02:44 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_textures(t_textures *textures)
{
    if (textures->no_line)
	    free(textures->no_line);
	if (textures->so_line)
		free(textures->so_line);
	if (textures->ea_line)
		free(textures->ea_line);
	if (textures->we_line)
		free(textures->we_line);
	free(textures);
}

void free_2d_map(t_game *game)
{
    size_t i;

	i = 0;
	if (!game->map_2d)
		return ;
	while (i < game->height)
	{
		free(game->map_2d[i]);
		i++;
	}
	free(game->map_2d);
}