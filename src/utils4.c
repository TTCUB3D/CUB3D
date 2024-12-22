/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:07:30 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/22 17:41:31 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
    int fd;

    if (!path || !*path)
        return (err("Texture path is empty"), 0);
    const char *extension = ft_strrchr(path, '.');
    if (!extension || (ft_strcmp(extension, ".xpm") != 0 && ft_strcmp(extension, ".png") != 0))
        return (err("Invalid texture file format"), 0);
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (err("Texture file not found"), 0);
    close(fd);
    return (1);
}

int all_paths_valid(t_textures *textures)
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
