/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:49:06 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/12 15:19:14 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map *head)
{
	t_map		*temp;

	temp = head;
	while (temp)
	{
		printf("%s\n", temp->line);
		temp = temp->next;
	}
}

void	print_matrix(char **map, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	print_texture_path(t_game *game)
{
	int	i;
	printf("N:%s\nS:%s\nW:%s\nE:%s\n", game->textures->no_line,
		game->textures->so_line, game->textures->we_line,
		game->textures->ea_line);
	i = 0;
	printf("C:%d, %d, %d\n", game->textures->ceil[i],
			game->textures->ceil[i + 1], game->textures->ceil[i + 2]);
	printf("F:%d, %d, %d\n", game->textures->floor[i],
			game->textures->floor[i + 1], game->textures->floor[i + 2]);
}