/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:48:18 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/23 13:50:00 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	only_nb(char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (is_space(line[i]))
		i++;
	return (line[i] == '\0');
}

int	start_with_zero(char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	return (line[i] == '0' && line[i + 1] != '\0' && (line[i + 1] >= '0'
			&& line[i + 1] <= '9'));
}

int	parse_color(const char *line, int color[3])
{
	int		i;
	char	**rgb;

	rgb = ft_split(line, ',');
	if (!rgb)
		return (0);
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		return (free_matrix(rgb), 0);
	i = 0;
	while (i < 3)
	{
		if (start_with_zero(rgb[i]))
			return (free_matrix(rgb), 0);
		if (!only_nb(rgb[i]))
			return (free_matrix(rgb), 0);
		color[i] = ft_atoi(rgb[i]);
		if (color[i] < 0 || color[i] > 255)
			return (free_matrix(rgb), 0);
		i++;
	}
	free_matrix(rgb);
	return (1);
}

void	flood_fill(t_map *head, size_t x, size_t y)
{
	size_t	width;
	size_t	height;
	char	current_char;

	get_map_dimensions(head, &width, &height);
	if (x >= height || y >= width)
		return ;
	current_char = get_char_at(head, x, y);
	if (current_char == '1' || current_char == 'F' || current_char == ' ')
		return ;
	set_char_at(head, x, y, 'F');
	flood_fill(head, x + 1, y);
	flood_fill(head, x - 1, y);
	flood_fill(head, x, y + 1);
	flood_fill(head, x, y - 1);
}

void	complete_flood(t_game *game, size_t x, size_t y)
{
	flood_fill(game->map, x, y);
	fill_from_zero(game);
}
