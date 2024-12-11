#include "cub3d.h"

// void	draw_minimap(t_mlx *mlx, t_game *game)
// {
//     size_t	i;
//     size_t	j;
//     void	*buffer;
//     int		bpp;
//     int		size_line;
//     int		endian;
//     char	*buff_data;

//     // Create an off-screen image (buffer)
//     buffer = mlx_new_image(mlx->mlx_pointer, game->width * MINI_TILE_SIZE, game->height * MINI_TILE_SIZE);
//     buff_data = mlx_get_data_addr(buffer, &bpp, &size_line, &endian);

//     i = 0;
//     while (i < game->height)
//     {
//         j = 0;
//         while (j < game->width)
//         {
//             if (game->map_2d[i][j] && game->map_2d[i][j] == '1')
//             {
//                 // Draw wall tile to the buffer
//                 for (int y = 0; y < MINI_TILE_SIZE; y++)
//                 {
//                     for (int x = 0; x < MINI_TILE_SIZE; x++)
//                     {
//                         mlx_put_pixe(buff_data, j * MINI_TILE_SIZE + x, i * MINI_TILE_SIZE + y, 0x0000FF, size_line, bpp); // White color for walls
//                     }
//                 }
//             }
//             else if ((game->map_2d[i][j]) && (game->map_2d[i][j] == '0'
//                     || game->map_2d[i][j] == 'N' || game->map_2d[i][j] == 'W'
//                     || game->map_2d[i][j] == 'E' || game->map_2d[i][j] == 'S'))
//             {
//                 // Draw floor tile to the buffer
//                 for (int y = 0; y < MINI_TILE_SIZE; y++)
//                 {
//                     for (int x = 0; x < MINI_TILE_SIZE; x++)
//                     {
//                         mlx_put_pixe(buff_data, j * MINI_TILE_SIZE + x, i * MINI_TILE_SIZE + y, 0xADD8E6, size_line, bpp); // Black color for floors
//                     }
//                 }
//                 // Draw grid lines to the buffer
//                 for (int x = 0; x < MINI_TILE_SIZE; x++)
//                 {
//                     mlx_put_pixe(buff_data, j * MINI_TILE_SIZE + x, i * MINI_TILE_SIZE, GRID_CLOLUR, size_line, bpp);
//                     mlx_put_pixe(buff_data, j * MINI_TILE_SIZE + x, (i + 1) * MINI_TILE_SIZE - 1, GRID_CLOLUR, size_line, bpp);
//                 }
//                 for (int y = 0; y < MINI_TILE_SIZE; y++)
//                 {
//                     mlx_put_pixe(buff_data, j * MINI_TILE_SIZE, i * MINI_TILE_SIZE + y, GRID_CLOLUR, size_line, bpp);
//                     mlx_put_pixe(buff_data, (j + 1) * MINI_TILE_SIZE - 1, i * MINI_TILE_SIZE + y, GRID_CLOLUR, size_line, bpp);
//                 }
//             }
//             j++;
//         }
//         i++;
//     }
// 	//put the buffer into the window
//     mlx_put_image_to_window(mlx->mlx_pointer, mlx->window, buffer, 0, 0);
//     mlx_destroy_image(mlx->mlx_pointer, buffer);
// }


// void draw_mini_rays(t_mlx *mlx, t_game *game)
// {
// 	int	player_x;
// 	int	player_y;
// 	float step_x;
// 	float step_y;
// 	float ray_angle;
// 	size_t map_x;
// 	size_t map_y;


// 	player_x = mlx->player->player_x * MINI_TILE_SIZE;
// 	player_y = mlx->player->player_y * MINI_TILE_SIZE;
// 	for (int  i = -30; i < mlx->player->fov/2; i++)
// 	{
// 		ray_angle = mlx->player->player_angle  + (i * (PI/180));
// 		mlx->player->mini_ray_x = player_x;
// 		mlx->player->mini_ray_y = player_y;
// 		step_x = cos(ray_angle) * 0.1;
// 		step_y = sin(ray_angle) * 0.1;
// 		while (1)
// 		{
// 			map_x = (int)(mlx->player->mini_ray_x/MINI_TILE_SIZE);
// 			map_y = (int)(mlx->player->mini_ray_y/MINI_TILE_SIZE);
// 			if (map_x >= 0 && map_x < game->width && map_y >= 0 && map_y < game->height && game->map_2d[map_y][map_x] == '1')
// 			{
// 				break;
// 			}
// 			mlx_pixel_put(mlx->mlx_pointer, mlx->window, (int)mlx->player->mini_ray_x, (int)mlx->player->mini_ray_y , 0xFF0000);
// 			mlx->player->mini_ray_x += step_x;
// 			mlx->player->mini_ray_y += step_y;
// 			if (mlx->player->mini_ray_x < 0 || mlx->player->mini_ray_x >= game->width * MINI_TILE_SIZE || mlx->player->mini_ray_y < 0 || mlx->player->mini_ray_y >= game->height * MINI_TILE_SIZE)
//             {
//                 break;
//             }
// 		}
// 	}
// }

// int	draw_minimap_player(t_mlx *mlx, t_game *game)
// {
// 	int	player_x;
// 	int	player_y;

// 	player_x = mlx->player->player_x * MINI_TILE_SIZE;
// 	player_y = mlx->player->player_y * MINI_TILE_SIZE;
// 	(void)game;
// 	// Draw the player as a small square or a different color pixel
// 	for (int y = 0; y < 1; y++)
// 	{
// 		for (int x = 0; x < 1; x++)
// 		{
// 			mlx_pixel_put(mlx->mlx_pointer, mlx->window, player_x + x, player_y
// 				+ y, PLAYER_COLOR);
// 		}
// 	}
// 	draw_mini_rays(mlx, game);
// 	return (0);
// }