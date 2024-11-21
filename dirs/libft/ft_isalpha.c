/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:53:35 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/15 13:08:08 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	char test_chars[] = {'a', 'Z', '5', '!', ' '
				// , '\n', 'b', '1', 'G', '*', '0'};
// 	int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);
// 	int i = 0;
// 	while (i < num_tests)
// 	{
// 		char ch = test_chars[i];
// 		int result = ft_isalpha(ch);

// 		if (result)
// 			printf("Character '%c' is alpha.\n", ch);
// 		else 
// 			printf("Character '%c' is not alpha.\n", ch);
// 		i++;
// 	}
// 	return (0);
// }
