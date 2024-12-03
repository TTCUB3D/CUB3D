/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:12:11 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/15 13:25:47 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (s[i] == (char)c)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*
- stringreversecharacter;
- compared to strchr(), this one is looking for the last occurance of
the given char 'c' int the string 's';
- 20 we check for c = '\0';
*/

//  #include <stdio.h>
// int main (void)
// {
// 	char *str = "abgcdefghgij";
// 	char c = 'g';
// 	char *dest;

// 	dest = ft_strrchr(str, c);
// 	printf("%s\n", dest);
// }
