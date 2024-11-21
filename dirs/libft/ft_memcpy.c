/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:22:50 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/17 11:37:38 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*pdest;
	const char	*psrc;
	size_t		i;

	pdest = (char *)dest;
	psrc = (const char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < len)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}
/*
-difference between memmove and this is that memmove doesn't
allow memory overlapping, making memcpy less safe, but faster;
-memcpy() cpoies n chars from 'src' to 'dest'.
*/

// #include <stdio.h>

// int main(void)
// {
// 	char src[] = "Hello, world!";
// 	char dst[10];
// 	ft_memcpy(dst, src, sizeof(src));
// 	printf("%s\n", dst);
// 	return (0);	
// }
