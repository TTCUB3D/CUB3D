/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:18:59 by tlupu             #+#    #+#             */
/*   Updated: 2024/12/23 16:36:41 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_rest_ang(t_player *player, t_game *game)
{
	if (player->direction == 'W')
	{
		player->player_angle = 3.14159f;
		game->plan_x = 0;
		game->plan_y = -0.66;
	}
	else if (player->direction == 'E')
	{
		player->player_angle = 0.0f;
		game->plan_x = 0;
		game->plan_y = 0.66;
	}
}

void	init_angle(t_player *player, t_game *game)
{
	if (player->direction == 'N')
	{
		player->player_angle = 4.71239f;
		game->plan_x = 0.66;
		game->plan_y = 0;
	}
	else if (player->direction == 'S')
	{
		player->player_angle = 4.71239f;
		game->plan_x = -0.66;
		game->plan_y = 0;
	}
	else
		init_rest_ang(player, game);
	if (player->direction != 'N' && player->direction != 'S'
		&& player->direction != 'W' && player->direction != 'E')
	{
		printf("Error: player coordinates\n");
		exit(1);
	}
}

// Initalising player struct
void	init_x_y(t_player *player, t_game *game)
{
	player->player_x = get_player_x_position(game) + 0.003f;
	player->player_y = get_player_y_position(game) + 0.003f;
	player->fov = FOV;
	game->camera_x = 0;
	game->map_x = 0;
	game->map_y = 0;
	game->direct_x = -1;
	game->direct_y = 0;
	game->raydirect_x = 0;
	game->raydirect_y = 0;
	game->curr_frame_time = 0;
	game->prev_frame_time = 0;
	game->collision = false;
}

t_player	*init_player(t_game *game)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
	{
		free(player);
		return (NULL);
	}
	player->direction = player_is_char(game);
	init_angle(player, game);
	init_x_y(player, game);
	return (player);
}
