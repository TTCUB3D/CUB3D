/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:48:08 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/14 10:54:21 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}
//bzero is used to set a block of memory to zero
//*s is a pointer to the starting adress of the memory
//n = the number of bytes to be set to zero
//size_t is an unsigned long type, and we include <stddef.h> header for it
//and in printf for it or sizeof we use %zu;
//we iterate over the memory block and set every byte to 0

// #include <stdio.h>
// int	main(void)
// {
// 	char buffer[10] = "Hello";
// 	printf("Before ft_bzero: %s\n", buffer);

// 	ft_bzero(buffer, 10);

// 	printf("After ft_bzero:");
// 	int i = 0;
// 	while (i < 10)
// 	{
// 		printf("%d", (unsigned char)buffer[i]);
		// i++;
// 	}
// 	printf("\n");

// 	return (0);
// }