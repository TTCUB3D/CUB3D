/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:37:25 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/11 17:41:51 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*
- dst = the destination buffer where the string will be copied;
- size = size of dst buffer;
- src = source string to be copied;
- the function returns the total length of the string it tried to
create(it is equal to the length of 'src', regardles of wether the
copy was succesful or not), and copies the size - 1 chars from src into dst;
- we first calculate the length of 'src';
- if 'size' is 0, return the length of 'src';
*/

// #include <stdio.h>
// int	main(void)
// {
// 	const char	*src = "Hello, world!";
// 	char	dst[20];
// 	size_t size = sizeof(dst);
// 	size_t result = ft_strlcpy(dst, src, size);

// 	printf("Destination: %s\n", dst);
// 	printf("Length of src :%zu\n", result);

// 	char small_dst[5];
// 	size_t small_size = sizeof(small_dst);
// 	result = ft_strlcpy(small_dst, src, small_size);

// 	printf("Small destination: %s\n", small_dst);
// 	printf("Length of src:%zu\n", result);
// 	return (0);
// }
