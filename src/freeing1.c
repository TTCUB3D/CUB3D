/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:23:00 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/03 11:56:58 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void free_resources(t_game *game)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < 5)
// 	{
// 		if (game->img[i])
// 		{
// 			mlx_destroy_image(game->mlx, game->img[i]);
// 			game->img[i] = NULL;
// 		}
// 	}
// 	if (game->win)
// 	{
// 		mlx_clear_window(game->mlx, game->win);
// 		mlx_destroy_window(game->mlx, game->win);
// 	}
// 	if (game->mlx)
// 	{
// 		mlx_destroy_display(game->mlx);
// 		mlx_loop_end(game->mlx);
// 		free(game->mlx);
// 		game->mlx = NULL;
// 	}
// }

static void	free_program(t_game *game)
{
	if (game->map)
	{
		free_list(game->map);
		game->map = NULL;
	}
	if (game->map_2d)
	{
		free_2d_map(game);
		game->map_2d = NULL;
	}
	if (game->textures)
	{
		free_textures(game->textures);
		game->textures = NULL;
	}
}

int	propper_exit(t_game *game)
{
	// free_resources(game);
	free_program(game);
	return (0);
}

void	free_list(t_map *head)
{
    t_map	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->line);
		free(temp);
	}
}

void free_matrix(char **matrix)
{
	int i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}