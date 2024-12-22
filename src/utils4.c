/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:18:36 by tlupu             #+#    #+#             */
/*   Updated: 2024/12/19 17:18:39 by tlupu            ###   ########.fr       */
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
