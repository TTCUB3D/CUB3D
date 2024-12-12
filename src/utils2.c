/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:56:25 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/12 12:52:36 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_player_pos(t_map *head, size_t *x, size_t *y)
{
	t_map	*temp;
	size_t	i;
	size_t	j;

	temp = head;
	i = 0;
	while (temp)
	{
		j = 0;
		while (j < ft_strlen(temp->line))
		{
			if (is_player(temp->line[j]))
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		temp = temp->next;
		i++;
	}
}

char	*alloc_fill_row(char *line, size_t width)
{
	char	*row;
	size_t	j;

	row = malloc((width + 1) * sizeof(char));
	if (!row)
		return (NULL);
	j = 0;
	while (line[j] && j < width)
	{
		row[j] = line[j];
		j++;
	}
	while (j < width)
		row[j++] = ' ';
	row[j] = '\0';
	return (row);
}

char	**convert_map(t_game *game)
{
	char	**map_2d;
	t_map	*temp;
	size_t	i;

	map_2d = malloc(game->height * sizeof(char *));
	if (!map_2d)
		return (err("Memory error for 2d_map!"), NULL);
	temp = game->map;
	i = 0;
	while (temp)
	{
		if (!temp->line)
			return (err("Invalid map line!"), NULL);
		map_2d[i] = alloc_fill_row(temp->line, game->width);
		if (!map_2d[i])
		{
			while (i--)
				free(map_2d[i]);
			free(map_2d);
			return (err("Memory error for map row!"), NULL);
		}
		temp = temp->next;
		i++;
	}
	return (map_2d);
}


void	eliminate_spaces(t_textures *textures)
{
	if (!textures)
		return ;
	rmv_space_in_str(&textures->no_line);
	rmv_space_in_str(&textures->so_line);
	rmv_space_in_str(&textures->we_line);
	rmv_space_in_str(&textures->ea_line);
}

void	rmv_space_in_str(char **str)
{
	char	*src;
	char	*new_str;
	size_t	i;
	size_t	j;

	src = *str;
	new_str = malloc(ft_strlen(src) + 1);
	if (!new_str)
		return ;
	i = 0;
	j = 0;
	while (src[i])
	{
		if (!is_space(src[i]))
			new_str[j++] = src[i];
		i++;
	}
	new_str[j] = '\0';
	free(*str);
	*str = new_str;
}
