/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:54:28 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/14 10:54:46 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < (n - 1))
	{
		i++;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

// int main(void)
// {
// 	char *str1 = "Hello, world!";
//     char *str2 = "Hello, world!";
//     char *str3 = "Hello, everyone!";
//     char *str4 = "Hi there!";
//     size_t n = 5;

// 	printf("s1,s2: %d\n", ft_strncmp(str1, str2, n));
//     printf("s1,s2: %d\n", strncmp(str1, str2, n));

// 	printf("s1,s3: %d\n", ft_strncmp(str1, str3, n));
//  	printf("s1,s3: %d\n", strncmp(str1, str3, n));
// 	printf("s1,s4: %d\n", ft_strncmp(str1, str4, n));
// 	printf("s1,s4: %d\n", strncmp(str1, str4, n));

// 	printf("s4,s1: %d\n", ft_strncmp(str4, str1, n));
// 	printf("s4,s1: %d\n", strncmp(str4, str1, n));

// 	n = 20;// n greater than lenght of string
// 	printf("s1,s2: %d\n", ft_strncmp(str1, str2, n));
// 	printf("s1,s2: %d\n", strncmp(str1, str2, n));

// 	printf("s1,s3: %d\n", ft_strncmp(str1, str3, n));
// 	printf("s1,s3: %d\n", strncmp(str1, str3, n));

// 	printf("s1,s4: %d\n", ft_strncmp(str1, str4, n));
// 	printf("s1,s4: %d\n", strncmp(str1, str4, n));

// 	printf("s4,s1: %d\n", ft_strncmp(str4, str1, n));
// 	printf("s4,s1: %d\n", strncmp(str4, str1, n));

// 	printf("%d\n", ft_strncmp("abcdefg", "abcdxyz", 4));

// 	return (0);
// }
