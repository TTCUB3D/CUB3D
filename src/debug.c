/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:49:06 by tursescu          #+#    #+#             */
/*   Updated: 2024/11/21 12:19:29 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map *head)
{
	t_map	*temp;

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