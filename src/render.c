/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:16:00 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/23 16:00:07 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//  DDA starts. It's a loop that increments
// the ray with 1 square every time,
// until a wall is hit.
// Each time,
// either it jumps a square in the x-direction
//(with stepX) or a square in the y-direction (with stepY),
// it always jumps 1 square at once. If the
// ray's direction would be the x-direction,
// the loop will only have to jump a
// square in the x-direction everytime,
// because the ray will never change its y-direction.
// If the ray is a bit sloped to the y-direction,
// then every so many jumps in the x-direction, the ray will
// have to jump one square in the
// y-direction. If the ray is exactly the y-direction,
// it never has to jump in the x-direction, etc...
// sideDistX and sideDistY get incremented
// with deltaDistX with every jump in their direction,
// and mapX and mapY get incremented with stepX and stepY respectively.
//   When the ray has hit a wall, the loop ends, and then
// we'll know whether an x-side or y-side of a wall was
// hit in the variable "side",
// and what wall
// was hit with mapX and mapY. We won't know exactly where
// the wall was hit however,
// but that's
// not needed in this case because we won't use textured walls for now.
// START DDA !!!
// make fct
void	start_dda(t_game *game, t_mlx *mlx)
{
	game->collision = false;
	while (!game->collision)
	{
		final_dda_inits(game);
		if (game->map_x >= 0 && game->map_x < game->width && game->map_y >= 0
			&& game->map_y < game->height)
		{
			if (game->map_2d[game->map_y][game->map_x] == '1')
				wall_collision_orientations(game);
		}
		else
			break ;
	}
	if (game->side == 0)
	{
		game->ray_wall_length = (game->map_x - mlx->player->player_x + (1
					- game->stepx) / 2) / game->raydirect_x;
	}
	else
	{
		game->ray_wall_length = (game->map_y - mlx->player->player_y + (1
					- game->stepy) / 2) / game->raydirect_y;
	}
}
// We don't use the Euclidean distance to the point representing player,
// but instead the distance to the camera plane
//(or,
// the distance of the point projected on the camera direction to the player),
// to avoid the fisheye effect.
// The fisheye effect is an effect you see if you use the real distance,
// where all the walls become rounded,
// and can make you sick if you rotate
// printf("ray_wall_length: %f\n", game->ray_wall_length);

void	get_distance_load_textures(t_game *game)
{
	game->screen_line_height = (int)(S_HEIGHT / game->ray_wall_length);
	if (game->screen_line_height > S_HEIGHT * 10)
		game->screen_line_height = S_HEIGHT * 10;
	game->draw_start = -(game->screen_line_height / 2) + (S_HEIGHT / 2);
	game->draw_end = (game->screen_line_height / 2) + (S_HEIGHT / 2);
	game->tex_y_offset = 0;
	if (game->draw_start < 0)
	{
		game->tex_y_offset = (-game->draw_start * TILE_SIZE)
			/ game->screen_line_height;
		game->draw_start = 0;
	}
	if (game->draw_end >= S_HEIGHT)
		game->draw_end = S_HEIGHT - 1;
	if (game->wall_orientation == 'n')
		game->text_data = game->textures->no_data;
	if (game->wall_orientation == 's')
		game->text_data = game->textures->so_data;
	if (game->wall_orientation == 'e')
		game->text_data = game->textures->ea_data;
	if (game->wall_orientation == 'w')
		game->text_data = game->textures->we_data;
}

void	draw_wall(t_mlx *mlx, t_game *game, int y, int x)
{
	if (game->side == 0)
		game->wall_x = mlx->player->player_y + game->ray_wall_length
			* game->raydirect_y;
	else
		game->wall_x = mlx->player->player_x + game->ray_wall_length
			* game->raydirect_x;
	game->wall_x -= floor(game->wall_x);
	if (game->wall_x < 0)
		game->wall_x = 0;
	else if (game->wall_x >= 1)
		game->wall_x = 1;
	game->tex_x = (int)(game->wall_x * TILE_SIZE);
	if (game->tex_x >= TILE_SIZE)
		game->tex_x = TILE_SIZE - 1;
	if ((game->side == 0 && game->raydirect_x > 0) || (game->side == 1
			&& game->raydirect_y < 0))
		game->tex_x = TILE_SIZE - game->tex_x - 1;
	game->tex_y = game->tex_y_offset + ((y - game->draw_start) * TILE_SIZE)
		/ game->screen_line_height;
	if (game->tex_y >= TILE_SIZE)
		game->tex_y = TILE_SIZE - 1;
	game->color = *((int *)(game->text_data + game->tex_y * TILE_SIZE
				* (game->bpp / 8) + game->tex_x * (game->bpp / 8)));
	mlx_put_pixel(game, x, y);
}

void	start_3d(t_mlx *mlx, t_game *game, int y, int x)
{
	if (y < game->draw_start)
		mlx_put_pixel_fc(game, x, y, game->textures->ceil_col);
	else if (y >= game->draw_start && y <= game->draw_end)
		draw_wall(mlx, game, y, x);
	else
		mlx_put_pixel_fc(game, x, y, game->textures->fl_col);
}

// Create an off-screen image (buffer)
void	start_rays(t_mlx *mlx, t_game *game)
{
	int	x;
	int	y;
	int	endian;

	x = 0;
	(void)y;
	game->buffer = mlx_new_image(mlx->mlx_pointer, S_WIDTH, S_HEIGHT);
	game->buff_data = mlx_get_data_addr(game->buffer, &game->bpp,
			&game->size_line, &endian);
	while (x < S_WIDTH)
	{
		y = 0;
		calculate_ray_init_vals(mlx, game, x);
		calculate_inital_first_ray_steps(mlx, game);
		start_dda(game, mlx);
		get_distance_load_textures(game);
		while (y < S_HEIGHT)
		{
			start_3d(mlx, game, y, x);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx_pointer, mlx->window, game->buffer, 0, 0);
	mlx_destroy_image(mlx->mlx_pointer, game->buffer);
}
