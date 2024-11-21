/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:15:58 by tursescu          #+#    #+#             */
/*   Updated: 2024/11/21 17:35:51 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

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
	propper_exit(&game);
	return (0);
}

int good_input(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		return (err("Memory error for textures!"), 0);
	// init_textures_null(game->textures);
	if (!parse_textures_colors(&(game->map), game->textures))
	{
		// free_textures(game->textures);
		return (0);	
	}
    if (!player_found(game->map))
    {
	    err("Player not found");
		// free_textures(game->textures);
		return (0);
	}
	game->just_map = copy_map(game->map);
	if (!game->just_map)
	{
		// free_textures(game->textures);
		return (err("Failedto copy map."), 0);
	}
	get_map_dimensions(game->just_map, &game->width, &game->height);
	game->map_2d = convert_map(game);
	if (!game->map_2d)
	{
		// free_list(game->just_map);
		// free_textures(game->textures);
		return (err("Failed to convert map"), 0);
	}
    if (!is_surrounded(game))
	{
		// propper_exit(game);
        return (err("Map is not enclosed by walls"), 0);
	}
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
