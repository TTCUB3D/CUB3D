/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:14:09 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/14 11:45:42 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_textures *textures)
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

void	free_2d_map(t_game *game)
{
	size_t	i;

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

void	destroy_all_img(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_pointer, mlx->background_img);
	mlx_destroy_image(mlx->mlx_pointer, mlx->minifloor_img);
	mlx_destroy_image(mlx->mlx_pointer, mlx->miniplayer_img);
	mlx_destroy_image(mlx->mlx_pointer, mlx->game->textures->no_text);
	mlx_destroy_image(mlx->mlx_pointer, mlx->game->textures->so_text);
	mlx_destroy_image(mlx->mlx_pointer, mlx->game->textures->ea_text);
	mlx_destroy_image(mlx->mlx_pointer, mlx->game->textures->we_text);
}