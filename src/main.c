/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:15:58 by tursescu          #+#    #+#             */
/*   Updated: 2024/11/21 12:24:19 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		err("Invalid ammount of arguments!");
		exit(0);
	}
	game.map = make_map(av[1]);
	if (!good_input(&game))
    {
		free_list(game.map);
		if (game.just_map)
			free_list(game.just_map);
        exit(0);
    }
    free_list(game.map);
    get_map_dimensions(game.just_map, &game.width, &game.height);
	game.map_2d = convert_map(&game);
	// printf("here 2d = \n");
	// print_matrix(game.map_2d, game.height);
	return (1);
}

int good_input(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures || !parse_textures_colors(&(game->map), game->textures))
		return (0);
    if (!player_found(game->map))
    {
	    err("Player not found");
		return (0);
	}
	game->just_map = copy_map(game->map);
	if (!game->just_map)
	{
		err("Failed to copy map");
		propper_exit(game);	
	}
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
		new_node = create_node(line);
		if (!new_node)
			break ;
		append_node(&head, new_node);
		line = get_next_line(fd);
	}
	close(fd);
	return (head);
}
