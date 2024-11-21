/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:21:03 by tursescu          #+#    #+#             */
/*   Updated: 2024/08/29 16:14:03 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_line(int fd, char *stash);
char	*set_stash(char *line);
void	*ft_free(char *buffer);
void	*ft_free_and_return(char *buffer, char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	line = fill_line(fd, stash);
	if (!line)
		return (NULL);
	stash = set_stash(line);
	if (!stash && *line == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*fill_line(int fd, char *stash)
{
	char	*temp;
	char	*buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(buffer));
		if (bytes_read == 0)
			return (ft_free_and_return(buffer, stash));
		buffer[bytes_read] = '\0';
		temp = stash;
		stash = ft_strjoin(stash, buffer);
		free(temp);
		if (!stash)
			return (ft_free(buffer));
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*set_stash(char *line)
{
	ssize_t	i;
	char	*rest;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	rest = ft_strdup(line + i + 1);
	if (!rest)
		return (NULL);
	if (rest[0] == '\0')
	{
		free(rest);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (rest);
}

void	*ft_free(char *buffer)
{
	free(buffer);
	return (NULL);
}

void	*ft_free_and_return(char *buffer, char *stash)
{
	free(buffer);
	return (stash);
}
