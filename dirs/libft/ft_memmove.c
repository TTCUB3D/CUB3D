/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:59:04 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/17 09:04:09 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*pdest;
	const char	*psrc;
	size_t		i;

	pdest = (char *)dest;
	psrc = (const char *)src;
	if ((!dest && !src) || dest == src)
		return (dest);
	if (dest <= src)
	{
		i = 0;
		while (i < len)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			pdest[len] = psrc[len];
	}
	return (dest);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *src = "hello";
// 	char dst[10];

// 	ft_memmove(dst, src, sizeof(src));

// 	printf("%s\n", dst);

// 	return (0);
// }