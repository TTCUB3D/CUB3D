/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:01:04 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/10 16:33:19 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*trim_newline(char *line)
{
	size_t	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}


int player_found(t_map *head)
{
	t_map	*temp;

	temp = head;
	while (temp)
	{
		if (has_char(temp->line, 'N') || has_char(temp->line, 'S')
			|| has_char(temp->line, 'W') || has_char(temp->line, 'E'))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	is_valid_adjacent(t_map *head, size_t x, size_t y)
{
	char	up;
	char	down;
	char	left;
	char	right;
	
	up = get_char_at(head, x - 1, y);
	down = get_char_at(head, x + 1, y);
	left = get_char_at(head, x, y - 1);
	right = get_char_at(head, x, y + 1);
	if (up == ' ' || down == ' ' || left == ' ' || right == ' ')
		return (0);
	return (1);
}

int	only_one_player(t_map *head)
{
	t_map	*temp;
	int		total_count;
	int		row_count;

	total_count = 0;
	temp = head;
	while (temp)
	{
		row_count = players_in_row(temp->line);
		if (row_count > 1)
			return (0);
		total_count += row_count;
		if (total_count > 1)
			return (0);
		temp = temp->next;
	}
	return (total_count == 1);
}