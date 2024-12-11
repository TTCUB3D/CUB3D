/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:09:20 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/10 16:37:07 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	has_bad_char(t_map *head)
{
	int		i;
	t_map	*temp;

	temp = head;
	while(temp)
	{
		i = 0;
		while (temp->line[i])
		{
			if (is_wrong_char(temp->line[i]))
				return (1);
			i++;
		}
		temp = temp->next;
	}
	return (0);
}

int	is_wrong_char(char c)
{
	if (!is_player(c) && c != '1' && c != '0' && c != ' ')
		return (1);
	return (0);
}

int players_in_row(const char *line)
{
	int	count;

	count = 0;
	while (*line)
	{
		if (is_player(*line))
			count++;
		if (count > 1)
			return (count);
		line++;
	}
	return (count);
}

int	is_empty_line(char *line)
{
	if (!line)
		return (1);
	while (*line)
	{
		if (!is_space(*line))
			return (0);
		line++;
	}
	return (1);
}

char	player_is_char(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map_2d[i])
	{
		j = 0;
		while (game->map_2d[i][j])
		{
			if (is_player(game->map_2d[i][j]))
				return (game->map_2d[i][j]);
			j++;
		}
		i++;
	}
	return ('X');
}