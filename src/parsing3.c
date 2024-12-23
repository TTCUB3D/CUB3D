/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:48:52 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/23 16:25:42 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void assign_val_to_flag(int *arr)
{
    int i;
    
    i = 0;
    while (i < 6)
    {
        arr[i] = 0;
        i++;
    }
}


int	parse_textures_colors(t_map **head, t_textures *textures)
{
	t_map	*temp;
	t_map	*current;
	int		should_free;
	int		seen_flag[6];
	int		i;

    assign_val_to_flag(seen_flag);
	current = *head;
	should_free = 1;
	while (current->next)
	{
		if (ft_strncmp(current->line, "NO", 2) == 0)
		{
			if (seen_flag[0]++)
			{
				err("Duplicate NO line");
				should_free = 0;
				break ;
			}
			textures->no_line = ft_strdup(current->line + 2);
		}
		else if (ft_strncmp(current->line, "SO", 2) == 0)
		{
			if (seen_flag[1]++)
			{
				err("Duplicate SO line");
				should_free = 0;
				break ;
			}
			textures->so_line = ft_strdup(current->line + 2);
		}
		else if (ft_strncmp(current->line, "EA", 2) == 0)
		{
			if (seen_flag[2]++)
			{
				err("Duplicate EA line");
				should_free = 0;
				break ;
			}
			textures->ea_line = ft_strdup(current->line + 2);
		}
		else if (ft_strncmp(current->line, "WE", 2) == 0)
		{
			if (seen_flag[3]++)
			{
				err("Duplicate WE line");
				should_free = 0;
				break ;
			}
			textures->we_line = ft_strdup(current->line + 2);
		}
		else if (ft_strncmp(current->line, "F", 1) == 0)
		{
			if (!parse_color(current->line + 1, textures->floor)
				|| seen_flag[4]++)
			{
				err("Invalid floor color or multiple F lines");
				should_free = 0;
				break ;
			}
		}
		else if (ft_strncmp(current->line, "C", 1) == 0)
		{
			if (!parse_color(current->line + 1, textures->ceil)
				|| seen_flag[5]++)
			{
				err("Invalid ceiling color or multiple C lines");
				should_free = 0;
				break ;
			}
		}
		else
			break ;
		temp = current;
		current = current->next;
		free(temp->line);
		free(temp);
	}
	if (should_free)
	{
		i = 0;
		while (i < 6)
		{
			if (seen_flag[i] == 0)
			{
				err("Missing texture path, color or map");
				free_list(current);
				*head = NULL;
				return (0);
			}
			i++;
		}
		*head = current;
	}
	else
	{
		*head = NULL;
		while (current)
		{
			temp = current;
			current = current->next;
			free(temp->line);
			free(temp);
		}
	}
	return (should_free);
}

