#include "cub3d.h"

int	close_on_button(t_mlx *mlx)
{
	printf("Game over !\n");
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

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
	{
		printf("Game over!\n");
		propper_exit(mlx);
	}
	if (keycode == D_KEY)
	{
		move_player(mlx, mlx->game, mlx->player, 0, -0.2);
	}
	if (keycode == A_KEY)
	{
		move_player(mlx, mlx->game, mlx->player, 0, 0.2);
	}
	if (keycode == S_KEY)
	{
		move_player(mlx, mlx->game, mlx->player, -0.2, 0);
	}
	if (keycode == W_KEY)
	{
		move_player(mlx, mlx->game, mlx->player, 0.2, 0);
	}
	if (keycode == LEFT_KEY)
	{
		mlx->player->player_angle -= 0.1;
		if(mlx->player->player_angle < 0)
			mlx->player->player_angle += 2 * PI;
		// draw_minimap(mlx,mlx->game);
		// draw_minimap_player(mlx,mlx->game);
	}
	if (keycode == RIGHT_KEY)
	{
		mlx->player->player_angle += 0.2;
		if(mlx->player->player_angle >= 2 * PI)
			mlx->player->player_angle -= 2 * PI;
		// draw_minimap(mlx,mlx->game);
		// draw_minimap_player(mlx,mlx->game);
	}
	start_rays(mlx, mlx->game);
	return (0);
}

int	setup_hooks(t_mlx *mlx)
{
	if (!mlx || !mlx->window)
	{
		printf("Error: mlx or window not initialized\n");
		return (1);
	}
	mlx_hook(mlx->window, 2, 1L << 0, key_hook, mlx);
	// mlx_loop_hook(mlx->mlx_pointer, draw_minimap_player, mlx);
	mlx_hook(mlx->window, 17, 0L, close_on_button, mlx);
	return (0);
}
