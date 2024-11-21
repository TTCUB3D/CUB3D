/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:59:58 by tursescu          #+#    #+#             */
/*   Updated: 2024/11/21 18:58:02 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	get_char_at(t_map *head, size_t x, size_t y)
{
	size_t	i;
	t_map	*temp;

	i = 0;
	temp = head;
	while (temp && i < x)
	{
		temp = temp->next;
		i++;
	}
	if (!temp || y >= ft_strlen(temp->line))
		return (' ');
	return (temp->line[y]);
	
}

void	set_char_at(t_map *head, size_t x, size_t y, char c)
{
	size_t	i;
	t_map	*temp;

	i = 0;
	temp = head;
	while (temp && i < x)
	{
		temp = temp->next;
		i++;
	}
	if (!temp || y >= ft_strlen(temp->line))
		return ;
	temp->line[y] = c;
}

void	get_map_dimensions(t_map *head, size_t *width, size_t *height)
{
	t_map	*temp;
	size_t	current_width;
	size_t	max_width;
	size_t	row_count;

	temp = head;
	max_width = 0;
	row_count = 0;
	while (temp)
	{
		current_width = ft_strlen(temp->line);
		if (current_width > max_width)
			max_width = current_width;
		row_count++;
		temp = temp->next;
	}
	*width = max_width;
	*height = row_count;
}

void fill_from_zero(t_map *head)
{
	size_t	width, height;
	size_t  x, y;
	char	current;

	get_map_dimensions(head, &width, &height);
	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			current = get_char_at(head, x, y);
			if (current == '0')
				flood_fill(head, x, y);
			y++;
		}
		x++;
	}
}

int is_surrounded(t_game *game)
{
	size_t	player_x;
	size_t	player_y;
	size_t	i;
	size_t	j;
	t_map	*temp;

	player_x = 0;
	player_y = 0;
	find_player_pos(game->map, &player_x, &player_y);
	complete_flood(game->map, player_x, player_y);
	temp = game->map;
	i = 0;
	while (temp)
	{
		j = 0;
		while(j < ft_strlen(temp->line))
		{
			if (temp->line[j] == 'F')
			{
				if (!is_valid_adjacent(game->map, i, j))
					return (0);
			}
			j++;
		}
		temp = temp->next;
		i++;
	}
	return (1);
}
