#include "../inc/cub3d.h"

#define WIDTH 10
#define HEIGHT 10
#define PI 3.14159265
#define	FOV 60


#define N 'N'
#define S 'S'
#define W 'W'
#define E 'E'

char		map[HEIGHT][WIDTH] = {{'1', '1', '1', '1', '1', '1', '1', '1',
			'1'}, {'1', '0', '0', '0', '0', '0', '0', '0', '1'}, {'1', '0', '0',
			'0', '0', '0', '0', '0', '1'}, {'1', '0', '0', '0', '0', '0', '0',
			'0', '1'}, {'1', '0', '0', '0', '0', '0', '0', '0', '1'}, {'1', '0',
			'0', '0', 'N', '0', '0', '0', '1'}, {'1', '0', '0', '0', '0', '0',
			'0', '0', '1'}, {'1', '0', '0', '0', '0', '0', '0', '0', '1'}, {'1',
			'0', '0', '0', '0', '0', '0', '0', '1'}, {'1', '1', '1', '1', '1',
			'1', '1', '1', '1'}};

void	init_angle(t_player *player)
{
	if (player->direction == 'N')
		player->player_angle = 4.71239f;
	else if (player->direction == 'S')
		player->player_angle = 4.699998f;
	else if (player->direction == 'W')
		player->player_angle = 3.14159f;
	else if (player->direction == 'E')
		player->player_angle = 0.0f;
	else
    {
		printf("Error: player coordinates\n");
        exit(1);
    }
}

// Initalising player struct

int	get_player_x_position(void)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				return (j);
			j++;
		}
		i++;
	}
    return(0);
}

int	get_player_y_position(void)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				return (i);
			j++; 
		}
		i++;
	}
    return(0);
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

void	init_x_y(t_player *player)
{

	player->player_x = get_player_x_position() + 0.003f;
	player->player_y = get_player_y_position() + 0.003f;
	player->fov = FOV;
}
t_player *init_player(char direction)
{
	t_player *player;
	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
	{
		free(player);
		return NULL;
	}
	player->direction = direction;
	init_angle(player);
	init_x_y(player);
	// init_coordinates(player);
	return(player);
}

void	draw_minimap(t_mlx *mlx)
{
	int i = 0;
	int j = 0;
	while (i <= WIDTH)
	{
		j = 0;
		while (j <= HEIGHT)
		{
				mlx_put_image_to_window(mlx->mlx_pointer, mlx->window, mlx->background_img,
					j * 60, i * 60);
			j++;
		}
		i++;
	}

}

// void draw_minimap_player(t_mlx *mlx)
// {
// }

void start_game(t_mlx *mlx)
{
    mlx->window = mlx_new_window(mlx->mlx_pointer, 650, 650, "cub3d");
    if (!mlx->window)
    {
        printf("Error: Window creation failed\n");
        exit(1);
    }
	int width = 60;
	int height = 60;
	mlx->background_img = mlx_xpm_file_to_image(mlx->mlx_pointer, PATH_TO_MINIMAP, &width,&height);
	draw_minimap(mlx);
	// draw_minimap_player(mlx);
	mlx_loop(mlx->mlx_pointer);
}

int	main(void)
{
	t_mlx		mlx;
	t_player	*player;

	mlx.mlx_pointer = mlx_init();
	player = init_player('N');
	start_game(&mlx);
	(void)player;
	return(0);
}
