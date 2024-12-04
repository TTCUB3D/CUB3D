#include "cub3d.h"

#define PI 3.14159265
#define FOV 60

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
t_player	*init_player(char direction, t_game *game)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
	{
		free(player);
		return (NULL);
	}
	player->direction = direction;
	init_angle(player);
	init_x_y(player, game);
	// init_coordinates(player);
	return (player);
}

void	draw_minimap(t_mlx *mlx, t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map_2d[i][j] && game->map_2d[i][j] == '1')
			{
				mlx_put_image_to_window(mlx->mlx_pointer, mlx->window,
					mlx->background_img, j * MINI_TILE_SIZE, i * MINI_TILE_SIZE);
			}
			else if (game->map_2d[i][j] && game->map_2d[i][j] == '0')
			{
				mlx_put_image_to_window(mlx->mlx_pointer, mlx->window,
					mlx->minifloor_img, j * MINI_TILE_SIZE ,i * MINI_TILE_SIZE);
			}
			j++;
		}
		i++;
	}
}

void draw_minimap_player(t_mlx *mlx, t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map_2d[i][j] && game->map_2d[i][j] == '1')
			{
				mlx_put_image_to_window(mlx->mlx_pointer, mlx->window,
					mlx->background_img, j * MINI_TILE_SIZE, i * MINI_TILE_SIZE);
			}
			j++;
		}
		i++;
	}
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
	draw_minimap(mlx, game);
	draw_minimap_player(mlx);
	mlx_loop(mlx->mlx_pointer);
}

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
	{
		propper_exit(&game);
		exit(1);
	}
	player = init_player('N', &game);
	start_game(&mlx, &game);
	propper_exit(&game);
	return (0);
}

int	good_input(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		return (err("Memory error for textures!"), 0);
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