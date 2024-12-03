/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:41:32 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/17 10:48:48 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	size_t	length;
	void	*point;

	if (nb == 0 && size == 0)
		return (malloc(0));
	length = nb * size;
	point = malloc(length);
	if (point == NULL)
		return (NULL);
	else
		ft_bzero(point, length);
	return (point);
}

/*
-calloc() allocates memory for an array of 'nb' elements of 'size' bytes each
and returns a pointer (*point) to the allocated memory.
-the memory is set to zero, that is why we use the ft_bzero function.
- malloc(nb * size);(man)
*/

// #include <stdio.h>

// int main(void)
// {
// 	size_t count = 5;
// 	size_t size = sizeof(int);
// 	int *array = (int *)ft_calloc(count, size);
// 	if (!array)
// 	{
// 		printf("Allocation failed!");
// 		return (1);
// 	}
// 	printf("Elements of array after ft_calloc:\n");
// 	size_t i = 0;
// 	while (i < count)
// 	{
// 		printf("array [%zu] = %d\n", i, array[i]);
// 		i++;
// 	}
// 	free(array);
// 	return (0);
// }

/*
-we use ft_calloc to allocate mem to an array of 5 ints.
-we check afterwards that all elements are initialized to 0.
- %zu is for size_t variables.
-finally we free the allocated memory.
!- to check with gcc add ft_bzero.c.
*/