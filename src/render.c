#include "cub3d.h"

//camer_x is the x position on the camera plane that the current x (pos) represents in the screen;
//plane_x and plane_y represent the 2d raycaster version of camera plane
//mapX and mapY represent the current square of the map the ray is in.
//sideDistX and sideDistY are initially the distance the ray has to travel from
// its start position to the first x-side and the first y-side.
//deltaDistX and deltaDistY are the distance the ray has to travel 
// to go from 1 x-side to the next x-side, or from 1 y-side to the next y-side.
// side checks if the NS or WE collisions suchs as wall hit

void calculate_ray_init_vals(t_mlx *mlx, t_game *game, size_t x)
{
	float epsilon;
	float player_angle;
	epsilon = 1e-30;// small val to avoid division to 0
	player_angle = mlx->player->player_angle;

	game->direct_x = cos(player_angle);
    game->direct_y = sin(player_angle);

    // Calculate plane vector (perpendicular to direction vector)
    game->plan_x = -sin(player_angle) * 0.66; // 0.66 is the field of view factor
    game->plan_y = cos(player_angle) * 0.66;

	game->camera_x = 2 * x/(float)S_WIDTH - 1;
		game->raydirect_x = game->direct_x + game->plan_x * game->camera_x; 
		game->raydirect_y = game->direct_y + game->plan_y * game->camera_x;
		game->map_x = (int)mlx->player->player_x ;
		game->map_y = (int)mlx->player->player_y ;
		//
		//deltas are calculated using pythagoras theoreme, the simplifeied version of the classic formula is below
		game->delta_ray_dist_x = fabs(1/(game->raydirect_x + epsilon));
		game->delta_ray_dist_y = fabs(1/(game->raydirect_y + epsilon));
}

//The DDA algorithm will always jump exactly one square each loop, 
		//either a square in the x-direction, or a square in the y-direction. If it has to go in the negative or positive 
		//x-direction, and the negative or positive y-direction will 
		//depend on the direction of the ray, and this fact will be stored
		// in stepX and stepY. Those variables are always either -1 or +1.
		//Make Fct
		//calc inital sidedistance and step

void calculate_inital_first_ray_steps(t_mlx *mlx, t_game *game)
{
	if (game->raydirect_x < 0)
		{
			game->stepx = -1;
			game->first_ray_dist_x = (mlx->player->player_x - game->map_x) * game->delta_ray_dist_x;
		}
		else
		{
			game->stepx = 1;
			game->first_ray_dist_x = (game->map_x + 1.0 - mlx->player->player_x) * game->delta_ray_dist_x;
		}
		if (game->raydirect_y < 0)
		{
			game->stepy = -1;
			game->first_ray_dist_y = (mlx->player->player_y - game->map_y) * game->delta_ray_dist_y;
		}
		else
		{
			game->stepy = 1;
			game->first_ray_dist_y = (game->map_y +  1.0 - mlx->player->player_y) * game->delta_ray_dist_y;
		}
}

void start_rays(t_mlx *mlx, t_game *game)
{
	int x;
	int screen_line_height;
	int draw_start;
	int draw_end;
	void	*buffer;
    int		bpp;
    int		size_line;
    int		endian;
    char	*buff_data;

    // Create an off-screen image (buffer)
    buffer = mlx_new_image(mlx->mlx_pointer, S_WIDTH, S_HEIGHT);
    buff_data = mlx_get_data_addr(buffer, &bpp, &size_line, &endian);

	for (x = 0; x < S_WIDTH; x++)
	{
//		ray_angle = mlx->player->player_angle  + (i * (PI/180));
// 		mlx->player->mini_ray_x = player_x;
// 		mlx->player->mini_ray_y = player_y;
// 		step_x = cos(ray_angle) * 0.1;
// 		step_y = sin(ray_angle) * 0.1;
		calculate_ray_init_vals(mlx, game, x);
		calculate_inital_first_ray_steps(mlx, game);
		//  DDA starts. It's a loop that increments the ray with 1 square every time, until a wall is hit.
		// Each time, either it jumps a square in the x-direction (with stepX) or a square in the y-direction (with stepY),
		// it always jumps 1 square at once. If the ray's direction would be the x-direction, the loop will only have to jump a
		 //square in the x-direction everytime, because the ray will never change its y-direction. 
		// If the ray is a bit sloped to the y-direction, then every so many jumps in the x-direction, the ray will 
		//have to jump one square in the y-direction. If the ray is exactly the y-direction, it never has to jump in the x-direction, etc...

		//sideDistX and sideDistY get incremented with deltaDistX with every jump in their direction,
		//and mapX and mapY get incremented with stepX and stepY respectively.

		//   When the ray has hit a wall, the loop ends, and then 
		//we'll know whether an x-side or y-side of a wall was hit in the variable "side", and what wall
 		//was hit with mapX and mapY. We won't know exactly where the wall was hit however, but that's
  		//not needed in this case because we won't use textured walls for now.

		//START DDA !!!
		//make fct
		game->collision = false;
		while (!game->collision)
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
			if (game->map_x >= 0 && game->map_x < game->width && game->map_y >= 0 && game->map_y < game->height)
            {
                if (game->map_2d[game->map_y][game->map_x] == '1')
                {
                    game->collision = true;
                }
            }
			else
			{
				break;
			}			
		}
		if (game->side == 0)
		{
			game->ray_wall_length = (game->map_x - mlx->player->player_x + (1 - game->stepx) / 2) / game->raydirect_x;
		}
		else
		{
			game->ray_wall_length = (game->map_y - mlx->player->player_y + (1 - game->stepy) / 2) / game->raydirect_y;
		}
		//We don't use the Euclidean distance to the point representing player, but instead the distance to the camera plane 
		//(or, the distance of the point projected on the camera direction to the player), to avoid the fisheye effect.
		//The fisheye effect is an effect you see if you use the real distance, where all the walls become rounded, and can make you sick if you rotate
		// printf("ray_wall_length: %f\n", game->ray_wall_length);
		screen_line_height = (int)(S_HEIGHT / game->ray_wall_length);
		draw_start = -(screen_line_height / 2) + (S_HEIGHT / 2);
		if (draw_start < 0)
		{
			draw_start = 0;
		}
		draw_end = (screen_line_height / 2) + (S_HEIGHT /2) ;
		if (draw_end >= S_HEIGHT)
		{
			draw_end = S_HEIGHT - 1;
		}
		for (int y = 0; y < draw_start; y++)
        {
			 mlx_put_pixel(buff_data, x, y, game->textures->ceil_col, size_line, bpp); //ceelong
        }
		for (int y = draw_start; y < draw_end; y++)
        {
			mlx_put_pixel(buff_data, x, y, 0xFFFFFF, size_line, bpp); //wall
        }
		for (int y = draw_end; y < S_HEIGHT; y++)
        {
			mlx_put_pixel(buff_data, x, y, game->textures->floor_col, size_line, bpp); //floor
        }
	}
	mlx_put_image_to_window(mlx->mlx_pointer, mlx->window, buffer, 0, 0);
	mlx_destroy_image(mlx->mlx_pointer, buffer);
}
