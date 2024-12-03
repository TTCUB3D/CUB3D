/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:00:03 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/17 11:40:44 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;

	i = (unsigned char *)s1;
	j = (unsigned char *)s2;
	while (n > 0)
	{
		if (*i != *j)
			return (*i - *j);
		i++;
		j++;
		n--;
	}
	return (0);
}
/*
-the memcmp() returns an int : 
* less than 0 if the first n bytes of s1 is less than the first n bytes of s2;
* equal to 0 if the first n bytes of s1 is equal to the first n bytes of s2;
* greater than 0 if the first n bytes of s1 is greater than the first n of s2;
- if n == 0 , return (0);
*/

// #include <stdio.h>

// int main(void)
// {
// 	const char str1[] = "Hello, world!";
// 	const char str2[] = "Hello, world!";
// 	size_t n = ft_strlen(str1);
// 	int result = ft_memcmp(str1, str2, n);

// 	if (result == 0)
// 		printf("The strings are identical.\n");
// 	else
// 		printf("Difference: %d\n", result);	
// 	const char str3[] = "Hello, world!";
// 	const char str4[] = "Hello, Grisha!";
// 	result = ft_memcmp(str3, str4, 10);
// 	if (result == 0)
// 		printf("The strings are identical.\n");
// 	else
// 		printf("Difference: %d\n", result);
// 	return (0);
// }