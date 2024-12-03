/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:28:35 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/15 13:00:41 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (ft_strchr(set, s1[end - 1]) && end > start)
			end--;
		str = malloc(sizeof(char) * (end - start + 1));
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, &s1[start], end - start + 1);
	}
	return (str);
}

/* 
- returns a copy of 's1' with the chars specified int 'set' removed
from the begining and the end;
-  
*/
// #include <stdio.h>
// #include <string.h>
// int main (void)
// {
// 	const char str1[] = "aaHelloaaopaaa aH";
// 	const char set[] = "aH";
// 	printf("%s\n", ft_strtrim(str1, set));
// }