/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:26:33 by tlupu             #+#    #+#             */
/*   Updated: 2024/12/23 15:38:12 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// camer_x is the x position on the camera plane
// that the current x (pos) represents in the screen;
// plane_x and plane_y represent the 2d raycaster
// version of camera plane
// mapX and mapY represent the current square
//  of the map the ray is in.
// sideDistX and sideDistY are initially the
//  distance the ray has to travel from
// its start position to the first x-side and
//  the first y-side.
// deltaDistX and deltaDistY are the distance
//  the ray has to travel
// to go from 1 x-side to the next x-side, or
// from 1 y-side to the next y-side.
// side checks if the NS or WE collisions
//  suchs as wall hit
// Calculate plane vector (perpendicular to direction vector)
//
// deltas are calculated using pythagoras theoreme,
// the simplifeied version of the classic formula is below()
void	calculate_ray_init_vals(t_mlx *mlx, t_game *game, size_t x)
{
	float	epsilon;
	float	player_angle;
	float	fov_factor;

	epsilon = 1e-30;
	player_angle = mlx->player->player_angle;
	game->direct_x = cos(player_angle);
	game->direct_y = sin(player_angle);
	fov_factor = 0.66;
	game->plan_x = -sin(player_angle) * fov_factor;
	game->plan_y = cos(player_angle) * fov_factor;
	game->camera_x = 2 * x / (float)S_WIDTH - 1;
	game->raydirect_x = game->direct_x + game->plan_x * game->camera_x;
	game->raydirect_y = game->direct_y + game->plan_y * game->camera_x;
	game->map_x = (int)mlx->player->player_x;
	game->map_y = (int)mlx->player->player_y;
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
// Derermine wall orientation

void	wall_collision_orientations(t_game *game)
{
	game->collision = true;
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
