/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:55:42 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/11 15:28:24 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*i;

	i = (char *)s;
	while (len > 0)
	{
		*i = c;
		i++;
		len--;
	}
	return (s);
}
/*
- memset fills the first 'len' bytes of the memory pointed by 's' 
with the constant byte 'c'.
- returns a pointer to the memory area 's';
- we type cast 's' to 'char *' to handle the memory block byte by byte.
- we itterate trough the pointer(i++) and fill every byte with the value of 'c'.
- the function returns the original pointer 's'.(start of memory block).
*/

// #include <stdio.h>
// int main(void)
// {
//     char src[30] = "Hello george";
// 	printf("%s\n", src);
// 	ft_memset(src, '$', sizeof(char) * 5);
// 	printf("%s\n", src);

// 	int arr[10];

// 	ft_memset(arr, 0, sizeof(int) * 10);
// 	int i = 0;
// 	while (i < 10)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	printf("\n");

// 	return (0);
// }