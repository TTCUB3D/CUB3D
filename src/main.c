#include "cub3d.h"

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
}
t_player	*init_player(t_game *game)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
	{
		free(player);
		return (NULL);
	}
	player->direction = player_is_char(game);
	init_angle(player);
	init_x_y(player, game);
	// init_coordinates(player);
	return (player);
}

void	mlx_put_pixe(char *buff_data, int x, int y, int color, int size_line, int bpp)
{
    int pixel_index = (y * size_line) + (x * (bpp / 8));
    *(unsigned int *)(buff_data + pixel_index) = color;
}

void	draw_minimap(t_mlx *mlx, t_game *game)
{
    size_t	i;
    size_t	j;
    void	*buffer;
    int		bpp;
    int		size_line;
    int		endian;
    char	*buff_data;

    // Create an off-screen image (buffer)
    buffer = mlx_new_image(mlx->mlx_pointer, game->width * MINI_TILE_SIZE, game->height * MINI_TILE_SIZE);
    buff_data = mlx_get_data_addr(buffer, &bpp, &size_line, &endian);

    i = 0;
    while (i < game->height)
    {
        j = 0;
        while (j < game->width)
        {
            if (game->map_2d[i][j] && game->map_2d[i][j] == '1')
            {
                // Draw wall tile to the buffer
                for (int y = 0; y < MINI_TILE_SIZE; y++)
                {
                    for (int x = 0; x < MINI_TILE_SIZE; x++)
                    {
                        mlx_put_pixe(buff_data, j * MINI_TILE_SIZE + x, i * MINI_TILE_SIZE + y, 0x0000FF, size_line, bpp); // White color for walls
                    }
                }
            }
            else if ((game->map_2d[i][j]) && (game->map_2d[i][j] == '0'
                    || game->map_2d[i][j] == 'N' || game->map_2d[i][j] == 'W'
                    || game->map_2d[i][j] == 'E' || game->map_2d[i][j] == 'S'))
            {
                // Draw floor tile to the buffer
                for (int y = 0; y < MINI_TILE_SIZE; y++)
                {
                    for (int x = 0; x < MINI_TILE_SIZE; x++)
                    {
                        mlx_put_pixe(buff_data, j * MINI_TILE_SIZE + x, i * MINI_TILE_SIZE + y, 0xADD8E6, size_line, bpp); // Black color for floors
                    }
                }
                // Draw grid lines to the buffer
                for (int x = 0; x < MINI_TILE_SIZE; x++)
                {
                    mlx_put_pixe(buff_data, j * MINI_TILE_SIZE + x, i * MINI_TILE_SIZE, GRID_CLOLUR, size_line, bpp);
                    mlx_put_pixe(buff_data, j * MINI_TILE_SIZE + x, (i + 1) * MINI_TILE_SIZE - 1, GRID_CLOLUR, size_line, bpp);
                }
                for (int y = 0; y < MINI_TILE_SIZE; y++)
                {
                    mlx_put_pixe(buff_data, j * MINI_TILE_SIZE, i * MINI_TILE_SIZE + y, GRID_CLOLUR, size_line, bpp);
                    mlx_put_pixe(buff_data, (j + 1) * MINI_TILE_SIZE - 1, i * MINI_TILE_SIZE + y, GRID_CLOLUR, size_line, bpp);
                }
            }
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(mlx->mlx_pointer, mlx->window, buffer, 0, 0);
    mlx_destroy_image(mlx->mlx_pointer, buffer);
}


void draw_mini_rays(t_mlx *mlx, t_game *game)
{
	int	player_x;
	int	player_y;
	float step_x;
	float step_y;
	float ray_angle;
	size_t map_x;
	size_t map_y;


	player_x = mlx->player->player_x * MINI_TILE_SIZE;
	player_y = mlx->player->player_y * MINI_TILE_SIZE;
	for (int  i = -30; i < mlx->player->fov/2; i++)
	{
		ray_angle = mlx->player->player_angle  + (i * (PI/180));
		mlx->player->mini_ray_x = player_x;
		mlx->player->mini_ray_y = player_y;
		step_x = cos(ray_angle) * 0.1;
		step_y = sin(ray_angle) * 0.1;
		while (1)
		{
			map_x = (int)(mlx->player->mini_ray_x/MINI_TILE_SIZE);
			map_y = (int)(mlx->player->mini_ray_y/MINI_TILE_SIZE);
			if (map_x >= 0 && map_x < game->width && map_y >= 0 && map_y < game->height && game->map_2d[map_y][map_x] == '1')
			{
				break;
			}
			mlx_pixel_put(mlx->mlx_pointer, mlx->window, (int)mlx->player->mini_ray_x, (int)mlx->player->mini_ray_y , 0xFF0000);
			mlx->player->mini_ray_x += step_x;
			mlx->player->mini_ray_y += step_y;
			if (mlx->player->mini_ray_x < 0 || mlx->player->mini_ray_x >= game->width * MINI_TILE_SIZE || mlx->player->mini_ray_y < 0 || mlx->player->mini_ray_y >= game->height * MINI_TILE_SIZE)
            {
                break;
            }
		}
	}
}

int	draw_minimap_player(t_mlx *mlx, t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = mlx->player->player_x * MINI_TILE_SIZE;
	player_y = mlx->player->player_y * MINI_TILE_SIZE;
	(void)game;
	// Draw the player as a small square or a different color pixel
	for (int y = 0; y < 1; y++)
	{
		for (int x = 0; x < 1; x++)
		{
			mlx_pixel_put(mlx->mlx_pointer, mlx->window, player_x + x, player_y
				+ y, PLAYER_COLOR);
		}
	}
	draw_mini_rays(mlx, game);
	return (0);
}

void	start_game(t_mlx *mlx, t_game *game)
{
	int	width;
	int	height;

	mlx->mlx_pointer = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_pointer, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "cub3d");
	if (!mlx->window)
	{
		printf("Error: Window creation failed\n");
		exit(1);
	}
	width = 60;
	height = 60;
	mlx->background_img = mlx_xpm_file_to_image(mlx->mlx_pointer,
			PATH_TO_MINIMAP, &width, &height);
	mlx->minifloor_img = mlx_xpm_file_to_image(mlx->mlx_pointer,
			PATH_TO_MINIFLOOR, &width, &height);
	mlx->miniplayer_img = mlx_xpm_file_to_image(mlx->mlx_pointer,
			PATH_TO_MINIPLAYER, &width, &height);
	draw_minimap(mlx, game);
	draw_minimap_player(mlx, game);
	mlx->game = game;
	setup_hooks(mlx);
	mlx_loop(mlx->mlx_pointer);
}
// MAIN

int	main(int ac, char **av)
{
	t_game		game;
	t_mlx		mlx;
	t_player	*player;

	init_game(&game);
	if (ac != 2)
		err("Invalid ammount of arguments!"), exit(0);
	game.map = make_map(av[1]);
	if (!game.map)
		err("Failed to parse map."), exit(0);
	if (!good_input(&game))
		free_program(&game);
	init_key_states(&mlx.key_states);
	player = init_player(&game);
	mlx.player = player;
	start_game(&mlx, &game);
	propper_exit(&mlx);
	return (0);
}

int	good_input(t_game *game)
{
	if (!parse_textures_colors(&(game->map), game->textures))
		return (0);
	eliminate_spaces(game->textures);
	if (!player_found(game->map))
		return (err("Player not found"), 0);
	if (!only_one_player(game->map))
		return (err("More than one player"), 0);
	print_texture_path(game);
	print_map(game->map);
	if (has_bad_char(game->map))
		return (err("Unrecognized charactr"), 0);
	get_map_dimensions(game->map, &game->width, &game->height);
	if (game->height > 100 || game->width > 200)
		return (err("Map too big"), 0);
	game->map_2d = convert_map(game);
	if (!game->map_2d)
		return (err("Failed to convert map"), 0);
	if (!is_surrounded(game))
		return (err("Map is not enclosed by walls"), 0);
	return (1);
}

t_map	*make_map(const char *file_path)
{
	int fd;
	char *line;
	t_map *head;
	t_map *new_node;

	head = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (NULL);
	}
	line = get_next_line(fd);
	while (line)
	{
		line = trim_newline(line);
		if (is_empty_line(line))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		new_node = create_node(line);
		if (!new_node)
			break ;
		append_node(&head, new_node);
		line = get_next_line(fd);
	}
	close(fd);
	return (head);
}
