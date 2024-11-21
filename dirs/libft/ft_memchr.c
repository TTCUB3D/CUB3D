/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:27:34 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/19 13:01:56 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*i;
	size_t	j;

	j = 0;
	i = (char *)s;
	while (j < n)
	{
		if (i[j] == (char)c)
			return (i + j);
		j++;
	}
	return (NULL);
}

/*
-ft_memchr() scans the initial 'n' bytes of the memory block pointed by 's' for
the first instance of 'c'.
-returns a pointer to the matching byte;
- 26 same thing as return ((char *)s + i);
*/

// #include <stdio.h>

// int main(void)
// {
// 	const char str[] = "Hello, world!";
// 	char c = 'o';
// 	size_t n = ft_strlen(str);
// 	char *result;
// 	result = (char *)ft_memchr(str, c, n);
// 	if (result != NULL)
// 		printf("Character '%c' found at position : %ld\n", c, result - str);
// 	else
// {
// 	printf("Character '%c' not found within the first %zu characters.\n", c, n);
// }
// 	c = 'z';
// 	result = (char *)ft_memchr(str, c, n);
// 	if (result != NULL)
// 		printf("Character '%c' found at position : %ld\n", c, result - str);
// 	else
// {
// 	printf("Character '%c' not found within the first %zu characters.\n", c, n);
// }
// 	return (0);
// }

/*
-we first test the function when the char c actually apears in the str.
-second test case is where c is not in str (from c = 'z').
*/