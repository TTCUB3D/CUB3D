#include "cub3d.h"

int close_on_button(t_game *game)
{
    printf("Game over !\n");
    propper_exit(game);
    return (0);
}

void	move_player(t_mlx *mlx, t_game *game, t_player *player, int dx, int dy)
{
	player->player_x += dx;
	player->player_y += dy;
	if (player->player_x >= 0 && player->player_x < game->width
		&& player->player_y >= 0 && player->player_y < game->height)
	{
		draw_minimap(mlx, game);
		draw_minimap_player(mlx, game);
	}
	else
	{
		player->player_x -= dx;
		player->player_y -= dy;
	}
}

int	key_hook(int keycode, t_mlx *mlx)
{

    if (keycode == ESC_KEY)
    {
        printf("Game over!\n");
        propper_exit(mlx->game);
    }
	if (keycode == W_KEY)
	{
		move_player(mlx, mlx->game, mlx->player, 0, -1);
	}
	if (keycode == S_KEY)
	{
	printf("PX IS :%p\n", mlx->player);
		move_player(mlx, mlx->game, mlx->player, 0, 1);
	}
	if (keycode == A_KEY || keycode == LEFT_KEY)
	{
		move_player(mlx, mlx->game, mlx->player, -1, 0);
	}
	if (keycode == D_KEY || keycode == RIGHT_KEY)
	{
		move_player(mlx, mlx->game, mlx->player, 1, 0);
	}
	return (0);
}

void	setup_hooks(t_mlx *mlx)
{
	if (!mlx || !mlx->window)
	{
		printf("Error: mlx or window not initialized\n");
		return ;
	}
	mlx_hook(mlx->window, 2, 1L << 0, key_hook, mlx->game);
	mlx_hook(mlx->window, 17, 0L, close_on_button, mlx->game);
}