#include "cub3d.h"

void	start_game(t_mlx *mlx, t_game *game)
{
	int	width;
	int	height;

	mlx->mlx_pointer = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_pointer, S_WIDTH,
			S_HEIGHT, "cub3d");
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
	// draw_minimap(mlx, game);
	// draw_minimap_player(mlx, game);
	// start_rays(mlx, game);
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
