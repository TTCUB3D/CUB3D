/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:15:05 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/13 15:08:51 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
- striteri(), compared to strmapi(), doesn't create a new string
with the results of the function, but it modifies the imput string 's' directly;
- it doesn't return anything (void);
*/

// #include <stdio.h>

// void my_function(unsigned int i, char *c)
// {
// 	if (i % 2 == 0)
// 		*c = ft_toupper(*c);
// }
// int main(void)
// {
// 	char str[] = "hello world!";
// 	printf("Before: %s\n", str);
// 	ft_striteri(str, my_function);
// 	printf("After: %s\n", str);
// }