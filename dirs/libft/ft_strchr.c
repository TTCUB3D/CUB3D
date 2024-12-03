/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:32:29 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/17 10:07:56 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
/*
-ft_strchr() returns a pointer to the first occurance of the char 'c'
in the string 's';
-if 'c' is not found, return NULL;
-if 'c' == NULL , the null terminator is still part of the string so
the function returns a pointer to the null terminator;
*/
// #include <stdio.h>
// int main (void)
// {
// 	char *str = "abgcdefghgij";
// 	char c = 'g';
// 	char d = '\0';
// 	printf("%s\n", ft_strchr(str, c));
// 	printf("%s\n", ft_strchr(str, d));
// }