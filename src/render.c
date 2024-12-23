/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:16:00 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/23 13:42:30 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// camer_x is the x position on the camera plane that the current x (pos) represents in the screen;
// plane_x and plane_y represent the 2d raycaster version of camera plane
// mapX and mapY represent the current square of the map the ray is in.
// sideDistX and sideDistY are initially the distance the ray has to travel from
// its start position to the first x-side and the first y-side.
// deltaDistX and deltaDistY are the distance the ray has to travel
// to go from 1 x-side to the next x-side, or from 1 y-side to the next y-side.
// side checks if the NS or WE collisions suchs as wall hit

void	calculate_ray_init_vals(t_mlx *mlx, t_game *game, size_t x)
{
	float	epsilon;
	float	player_angle;
	float	fov_factor;

	epsilon = 1e-30; // small val to avoid division to 0
	player_angle = mlx->player->player_angle;
	game->direct_x = cos(player_angle);
	game->direct_y = sin(player_angle);
	// Calculate plane vector (perpendicular to direction vector)
	fov_factor = 0.66;
	game->plan_x = -sin(player_angle) * fov_factor;
	// 0.66 is the field of view factor
	game->plan_y = cos(player_angle) * fov_factor;
	game->camera_x = 2 * x / (float)S_WIDTH - 1;
	game->raydirect_x = game->direct_x + game->plan_x * game->camera_x;
	game->raydirect_y = game->direct_y + game->plan_y * game->camera_x;
	game->map_x = (int)mlx->player->player_x;
	game->map_y = (int)mlx->player->player_y;
	//
	// deltas are calculated using pythagoras theoreme,
	// the simplifeied version of the classic formula is below
	game->delta_ray_dist_x = fabs(1 / (game->raydirect_x + epsilon));
	game->delta_ray_dist_y = fabs(1 / (game->raydirect_y + epsilon));
}

// The DDA algorithm will always jump exactly one square each loop,
// either a square in the x-direction,
// or a square in the y-direction. If it has to go in the negative or positive
// x-direction, and the negative or positive y-direction will
// depend on the direction of the ray, and this fact will be stored
// in stepX and stepY. Those variables are always either -1 or +1.
// Make Fct
// calc inital sidedistance and step

void	calculate_inital_first_ray_steps(t_mlx *mlx, t_game *game)
{
	if (game->raydirect_x < 0)
	{
		game->stepx = -1;
		game->first_ray_dist_x = (mlx->player->player_x - game->map_x)
			* game->delta_ray_dist_x;
	}
	else
	{
		game->stepx = 1;
		game->first_ray_dist_x = (game->map_x + 1.0 - mlx->player->player_x)
			* game->delta_ray_dist_x;
	}
	if (game->raydirect_y < 0)
	{
		game->stepy = -1;
		game->first_ray_dist_y = (mlx->player->player_y - game->map_y)
			* game->delta_ray_dist_y;
	}
	else
	{
		game->stepy = 1;
		game->first_ray_dist_y = (game->map_y + 1.0 - mlx->player->player_y)
			* game->delta_ray_dist_y;
	}
}

void	final_dda_inits(t_game *game)
{
	if (game->first_ray_dist_x < game->first_ray_dist_y)
	{
		game->first_ray_dist_x += game->delta_ray_dist_x;
		game->map_x += game->stepx;
		game->side = 0;
	}
	else
	{
		game->first_ray_dist_y += game->delta_ray_dist_y;
		game->map_y += game->stepy;
		game->side = 1;
	}
}

void	wall_collision_orientations(t_game *game)
{
	game->collision = true;
	// Derermine wall orientation
	if (game->side == 0)
	{
		if (game->raydirect_x > 0)
			game->wall_orientation = 'e';
		else
			game->wall_orientation = 'w';
	}
	else
	{
		if (game->raydirect_y > 0)
			game->wall_orientation = 's';
		else
			game->wall_orientation = 'n';
	}
}
//  DDA starts. It's a loop that increments the ray with 1 square every time,
// until a wall is hit.
// Each time,
// either it jumps a square in the x-direction (with stepX) or a square in the y-direction (with stepY),
// it always jumps 1 square at once. If the ray's direction would be the x-direction,
// the loop will only have to jump a
// square in the x-direction everytime,
// because the ray will never change its y-direction.
// If the ray is a bit sloped to the y-direction,
// then every so many jumps in the x-direction, the ray will
// have to jump one square in the y-direction. If the ray is exactly the y-direction,
// it never has to jump in the x-direction, etc...
// sideDistX and sideDistY get incremented with deltaDistX with every jump in their direction,
// and mapX and mapY get incremented with stepX and stepY respectively.
//   When the ray has hit a wall, the loop ends, and then
// we'll know whether an x-side or y-side of a wall was hit in the variable "side",
// and what wall
// was hit with mapX and mapY. We won't know exactly where the wall was hit however,
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
	{
		game->screen_line_height = S_HEIGHT * 10;
	}
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
	{
		game->draw_end = S_HEIGHT - 1;
	}
	if (game->wall_orientation == 'n')
		game->text_data = game->textures->no_data;
	if (game->wall_orientation == 's')
		game->text_data = game->textures->so_data;
	if (game->wall_orientation == 'e')
		game->text_data = game->textures->ea_data;
	if (game->wall_orientation == 'w')
		game->text_data = game->textures->we_data;
}

void	start_rays(t_mlx *mlx, t_game *game)
{
	int		x;
	void	*buffer;
	int		bpp;
	int		size_line;
	int		endian;
	char	*buff_data;
	float	wall_x;
	int		tex_x;
	int		tex_y;
	int		color;

	// Create an off-screen image (buffer)
	buffer = mlx_new_image(mlx->mlx_pointer, S_WIDTH, S_HEIGHT);
	buff_data = mlx_get_data_addr(buffer, &bpp, &size_line, &endian);
	for (x = 0; x < S_WIDTH; x++)
	{
		calculate_ray_init_vals(mlx, game, x);
		calculate_inital_first_ray_steps(mlx, game);
		start_dda(game, mlx);
		get_distance_load_textures(game);
		for (int y = 0; y < S_HEIGHT; y++)
		{
			if (y < game->draw_start)
				mlx_put_pixel(buff_data, x, y, game->textures->ceil_col,
					size_line, bpp); // ceiling
			else if (y >= game->draw_start && y <= game->draw_end)
			{
				if (game->side == 0)
					wall_x = mlx->player->player_y + game->ray_wall_length
						* game->raydirect_y;
				else
					wall_x = mlx->player->player_x + game->ray_wall_length
						* game->raydirect_x;
				wall_x -= floor(wall_x);
				if (wall_x < 0)
					wall_x = 0;
				else if (wall_x >= 1)
					wall_x = 1;
				tex_x = (int)(wall_x * TILE_SIZE);
				if (tex_x >= TILE_SIZE)
					tex_x = TILE_SIZE - 1;
				if ((game->side == 0 && game->raydirect_x > 0)
					|| (game->side == 1 && game->raydirect_y < 0))
				{
					tex_x = TILE_SIZE - tex_x - 1;
				}
				tex_y = game->tex_y_offset + ((y - game->draw_start)
						* TILE_SIZE) / game->screen_line_height;
				if (tex_y >= TILE_SIZE)
					tex_y = TILE_SIZE - 1;
				color = *((int *)(game->text_data + tex_y * TILE_SIZE * (bpp
								/ 8) + tex_x * (bpp / 8)));
				mlx_put_pixel(buff_data, x, y, color, size_line, bpp); // wall
			}
			else
				mlx_put_pixel(buff_data, x, y, game->textures->fl_col,
					size_line, bpp); // floor
		}
	}
	mlx_put_image_to_window(mlx->mlx_pointer, mlx->window, buffer, 0, 0);
	mlx_destroy_image(mlx->mlx_pointer, buffer);
}
