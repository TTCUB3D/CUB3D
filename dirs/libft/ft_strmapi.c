/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:38:29 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/12 09:11:35 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	i = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
-strmapi() applies a given function to each char of a string,
passing the char index and the char itself as args to the function,
and then makes a new string from the results of that function;
*/

// #include <stdio.h>

// char my_function(unsigned int i, char c)
// {
// 	if (i % 2 == 0) {
//         return ft_toupper(c);
//     } else {
//         return c;
//     }
// }

// int main(void)
// {
// 	const char *str = "hello, world!";
// 	char *result = ft_strmapi(str, my_function);
// 	if (result == NULL)
// 		printf("Allocation failed!");
// 	else
// 	{
// 		printf("Original: %s\n", str);
// 		printf("Changed: %s\n", result);
// 	}
// 	return (0);
// }