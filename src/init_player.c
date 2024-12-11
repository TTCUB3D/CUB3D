#include "cub3d.h"

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
	else if (player->direction == 'W')
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
	else
	{
		printf("Error: player coordinates\n");
		exit(1);
	}
}

// Initalising player struct

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

// void	init_coordinates(t_player *player)
// {
// 	if (player->direction == N)
// 		player->player_angle = 4.71239f;
// 	else if (player->direction == S)
// 		player->player_angle = 4.699998f;
// 	else if (player->direction == W)
// 		player->player_angle = 3.14159f;
// 	else if (player->direction == E)
// 		player->player_angle = 0.0f;
// 	else
//     {
//         exit(1);
// 		printf('Error: player coordinates\n");
//     }
// }

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
	game-> curr_frame_time = 0;
	game->prev_frame_time = 0;
	game->collision = false;
}
t_player	*init_player(char direction, t_game *game)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
	{
		free(player);
		return (NULL);
	}
	player->direction = direction;
	init_angle(player, game);
	init_x_y(player, game);
	// init_coordinates(player);
	return (player);
}


