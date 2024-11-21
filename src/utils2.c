/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:56:25 by tursescu          #+#    #+#             */
/*   Updated: 2024/11/21 12:17:35 by tursescu         ###   ########.fr       */
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

char	**convert_map(t_game *game)
{
	char	**map_2d;
	t_map	*temp;
	size_t	i;
	size_t	j;

	map_2d = malloc(game->height * sizeof(char *));
	if (!map_2d)
		return (err("Memory error for 2d_map!"), NULL);
	temp = game->just_map;
	i = 0;
	while (temp)
	{
		map_2d[i] = malloc((game->width + 1) * sizeof(char));
		if (!map_2d[i])
			return (err("Memory error for map row!"), NULL);
		j = 0;
		while (temp->line[j] &&j < game->width)
		{
			map_2d[i][j] = temp->line[j];
			j++;
		}
		while (j < game->width)
			map_2d[i][j++] = ' ';
		map_2d[i][j] = '\0';
		temp = temp->next;
		i++;
	}
	return (map_2d);
}
