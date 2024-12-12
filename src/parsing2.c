/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:48:18 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/12 15:04:10 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_textures_colors(t_map **head, t_textures *textures)
{
	t_map	*temp;
	t_map	*current;

	current = *head;
	while (current)
	{
		if (ft_strncmp(current->line, "NO ", 3) == 0)
			textures->no_line = ft_strdup(current->line + 3);
		else if (ft_strncmp(current->line, "SO ", 3) == 0)
			textures->so_line = ft_strdup(current->line + 3);
		else if (ft_strncmp(current->line, "EA ", 3) == 0)
			textures->ea_line = ft_strdup(current->line + 3);
		else if (ft_strncmp(current->line, "WE ", 3) == 0)
			textures->we_line = ft_strdup(current->line + 3);
		else if (ft_strncmp(current->line, "F ", 2) == 0)
		{
			if (!parse_color(current->line + 2, textures->floor))
				return (err("Invalid floor color"), 0);
		}
		else if (ft_strncmp(current->line, "C ", 2) == 0)
		{
			if (!parse_color(current->line + 2, textures->ceil))
				return (err("Invalid ceiling color"), 0);
		}
		else
			break ;
		temp = current;
		current = current->next;
		free(temp->line);
		free(temp);
	}
	*head = current;
	return (1);
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
		color[i] = ft_atoi(rgb[i]);
		if (color[i] < 0 || color[i] > 255)
		{
			free_matrix(rgb);
			return (0);
		}
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
