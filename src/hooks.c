#include "cub3d.h"

int	close_on_button(t_mlx *mlx)
{
	free(mlx->key_states);
	propper_exit(mlx);
	return (0);
}

void	move_player(t_mlx *mlx, t_game *game, t_player *player, float dx,
		float dy)
{
	float	new_x;
	float	new_y;

	new_x = player->player_x + dx * cos(mlx->player->player_angle) - dy * sin(mlx->player->player_angle);
	new_y = player->player_y + dx * sin(mlx->player->player_angle) + dy * cos(mlx->player->player_angle);
	if (new_x >= 0 && new_x < game->width && new_y >= 0 && new_y < game->height
		&& game->map_2d[(int)new_y][(int)new_x] != '1')
	{
		player->player_x = new_x;
		player->player_y = new_y;
		mlx->player = player;
		// draw_minimap(mlx, game);
		// draw_minimap_player(mlx, game);
	}
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode >= 0 && keycode < MAX_KEY_CODE)
		mlx->key_states[keycode] = true;
	return (0);
}

int key_release(int keycode, t_mlx *mlx)
{
	if (keycode >= 0 && keycode < MAX_KEY_CODE)
		mlx->key_states[keycode] = false;
	return (0);
}

void	process_keys(t_mlx *mlx)
{
	if (mlx->key_states[ESC_KEY])
		propper_exit(mlx);
	if (mlx->key_states[A_KEY])
		move_player(mlx, mlx->game, mlx->player, 0, -0.1);
	if (mlx->key_states[D_KEY])
		move_player(mlx, mlx->game, mlx->player, 0, 0.1);
	if (mlx->key_states[S_KEY])
		move_player(mlx, mlx->game, mlx->player, -0.1, 0);
	if (mlx->key_states[W_KEY])
		move_player(mlx, mlx->game, mlx->player, 0.1, 0);
	if (mlx->key_states[LEFT_KEY])
	{
		mlx->player->player_angle -= 0.1;
		if(mlx->player->player_angle < 0)
			mlx->player->player_angle += 2 * PI;
		// draw_minimap(mlx,mlx->game);
		// draw_minimap_player(mlx,mlx->game);
	}
	if (mlx->key_states[RIGHT_KEY])
	{
		mlx->player->player_angle += 0.2;
		if(mlx->player->player_angle >= 2 * PI)
			mlx->player->player_angle -= 2 * PI;
		// draw_minimap(mlx,mlx->game);
		// draw_minimap_player(mlx,mlx->game);
	}
	start_rays(mlx, mlx->game);
}

int	game_loop(t_mlx *mlx)
{
	process_keys(mlx);
	return (0);
}

int	setup_hooks(t_mlx *mlx)
{
	if (!mlx || !mlx->window)
	{
		printf("Error: mlx or window not initialized\n");
		return (1);
	}
	mlx_hook(mlx->window, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->window, 3, 1L << 1, key_release, mlx);
	mlx_hook(mlx->window, 17, 0L, close_on_button, mlx);
	mlx_loop_hook(mlx->mlx_pointer, game_loop, mlx);
	return (0);
}
