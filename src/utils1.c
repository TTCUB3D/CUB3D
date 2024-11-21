/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:47:34 by tursescu          #+#    #+#             */
/*   Updated: 2024/11/21 11:43:43 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*copy_map(t_map *og)
{
	t_map *new_head;
	t_map *current;
	t_map *new_node;

	new_head = NULL;
	current = og;
	new_node = NULL;
	while (current)
	{
		new_node = create_node(ft_strdup(current->line));
		if (!new_node)
		{
			free_list(new_head);
			return (NULL);
		}
		append_node(&new_head, new_node);
		current = current->next;
	}
	return (new_head);
}

void	err(char *str)
{
	printf("%sError\n", RED);
	printf("%s", str);
	printf("%s\n", RESET);
}

t_map	*create_node(char *line)
{
	t_map	*new_node;

	new_node = malloc(sizeof(t_map));
	if (!new_node)
		return (NULL);
	new_node->line = line;
	new_node->next = NULL;
	return (new_node);
}

void	append_node(t_map **head, t_map *new_node)
{
	t_map	*temp;

	if (!head || !new_node)
		return;
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

int has_char(const char *str, char c)
{
	size_t	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}