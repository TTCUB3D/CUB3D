/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:42:10 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/19 13:13:35 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

static size_t	word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_array(size_t	i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static char	**fill_arr(const char *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (s[j] && s[j] == c)
			j++;
		array[i] = ft_substr(s, j, word_len(&s[j], c));
		if (array[i] == NULL)
		{
			free_array(i, array);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (array == NULL)
		return (NULL);
	array = fill_arr(s, c, array, words);
	return (array);
}

// #include <stdio.h>
// int main (void)
// {
// 	char	*s = " 12-3 dasda *&#^@  Hello there, friend!!!";
// 	char	**v = ft_split(s, ' ');

// 	while (*v)
// 	{
// 		printf("%s\n", *v);
// 		v++;
// 	}
// }
/*
- the function allocates and returns an array of strings obtained
by splitting 's' using the char 'c' as a delimiter.
- the array must end with a NULL pointer;
1) Count the words in 's';
2) Allocate memory for the array of strings/matrix;
3) Coppy the word/token in the correct position
- 27 to iterate trough the whole word, without incrementing 'words' again
*/