/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:18:36 by tlupu             #+#    #+#             */
/*   Updated: 2024/12/23 16:10:05 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_player_x_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_2d[i])
	{
		j = 0;
		while (game->map_2d[i][j])
		{
			if (game->map_2d[i][j] == 'N' || game->map_2d[i][j] == 'S'
				|| game->map_2d[i][j] == 'W' || game->map_2d[i][j] == 'E')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_player_y_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_2d[i])
	{
		j = 0;
		while (game->map_2d[i][j])
		{
			if (game->map_2d[i][j] == 'N' || game->map_2d[i][j] == 'S'
				|| game->map_2d[i][j] == 'W' || game->map_2d[i][j] == 'E')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	is_valid_texture_path(const char *path)
{
	int			fd;
	const char	*extension = ft_strrchr(path, '.');

	if (!path || !*path)
		return (err("Texture path is empty"), 0);
	if (!extension || (ft_strcmp(extension, ".xpm") != 0 && ft_strcmp(extension,
				".png") != 0))
		return (err("Invalid texture file format"), 0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (err("Texture file not found"), 0);
	close(fd);
	return (1);
}

int	all_paths_valid(t_textures *textures)
{
	if (!is_valid_texture_path(textures->no_line))
		return (0);
	else if (!is_valid_texture_path(textures->so_line))
		return (0);
	else if (!is_valid_texture_path(textures->ea_line))
		return (0);
	else if (!is_valid_texture_path(textures->we_line))
		return (0);
	else
		return (1);
}
