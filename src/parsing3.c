/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:48:52 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/26 12:39:16 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_texture(char *line, int *seen_flag, char **texture_line,
		char *error_message)
{
	if ((*seen_flag)++)
	{
		err(error_message);
		return (0);
	}
	*texture_line = ft_strdup(line + 2);
	return (1);
}

static int	handle_color(char *line, int *seen_flag, int *color_array,
		char *error_message)
{
	if ((*seen_flag)++ || !parse_color(line, color_array))
	{
		err(error_message);
		return (0);
	}
	return (1);
}

static int	process_line(char *str, int *seen_flag, t_textures *textures)
{
	if (ft_strncmp(str, "NO", 2) == 0)
		return (handle_texture(str, &seen_flag[0], &textures->no_line,
				"Duplicate NO line"));
	else if (ft_strncmp(str, "SO", 2) == 0)
		return (handle_texture(str, &seen_flag[1], &textures->so_line,
				"Duplicate SO line"));
	else if (ft_strncmp(str, "EA", 2) == 0)
		return (handle_texture(str, &seen_flag[2], &textures->ea_line,
				"Duplicate EA line"));
	else if (ft_strncmp(str, "WE", 2) == 0)
		return (handle_texture(str, &seen_flag[3], &textures->we_line,
				"Duplicate WE line"));
	else if (ft_strncmp(str, "F", 1) == 0)
		return (handle_color(str + 1, &seen_flag[4], textures->floor,
				"Invalid floor color or multiple F lines"));
	else if (ft_strncmp(str, "C", 1) == 0)
		return (handle_color(str + 1, &seen_flag[5], textures->ceil,
				"Invalid ceiling color or multiple C lines"));
	else
		return (-1);
}

int	process_all_lines(t_map **current, int *seen_flag, t_textures *textures)
{
	t_map	*temp;
	int		result;

	while ((*current)->next)
	{
		result = process_line((*current)->line, seen_flag, textures);
		if (result == 0 || result == -1)
			return (result);
		jump_lines(&temp, current);
	}
	return (1);
}

int	parse_textures_colors(t_map **head, t_textures *textures)
{
	t_map	*current;
	int		should_free;
	int		seen_flag[6];

	current = *head;
	should_free = 1;
	initialize_seen_flags(seen_flag);
	should_free = process_all_lines(&current, seen_flag, textures);
	if (should_free && !check_missing_flags(seen_flag))
		should_free = 0;
	if (should_free)
		*head = current;
	else
		free_remaining_lines(&current, head);
	return (should_free);
}
