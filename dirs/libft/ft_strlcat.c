/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:24:30 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/11 18:11:06 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	while (src[src_len])
		src_len++;
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
-23-25 we first calculate the lengths of dst and src;
-27 if size is less than or equal to dest length, then return 
size + src length;
-30 we append src to dst;
-35 we append the null to dst;
-37 return the total length of the string the function tried to create;

*/

// #include <stdio.h>

// int main(void)
// {
// 	const char *src1 = "world!";
// 	char dst1[20] = "Hello, ";
// 	size_t size1 = sizeof(dst1);
// 	printf("Before: ds = %s\n", dst1);

// 	size_t result1 = ft_strlcat(dst1, src1, size1);
// 	printf("After: ds = %s\n", dst1);
// 	printf("Total length = %zu\n", result1);

// 	const char *src2 = "world!";
// 	char dst2[10] = "Hello, ";
// 	size_t size2 = sizeof(dst2);
// 	printf("Before(small buff): ds = %s\n", dst2);

// 	size_t result2 = ft_strlcat(dst2, src2, size2);
// 	printf("After(small buff): ds = %s\n", dst2);
// 	printf("Total length = %zu\n", result2);
// 	return (0);
// }
