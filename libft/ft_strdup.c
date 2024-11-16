/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:28:13 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/19 13:17:20 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
-the function returns a pointer to a new string which is a duplicate of
the string s.
*/

// #include <stdio.h>

// int main(void)
// {
//     char *str = "Hello, world";
//     char *dest;

//     dest = ft_strdup(str);
//     printf("%s\n", dest);
//     free(dest);
//     return (0);   
// }