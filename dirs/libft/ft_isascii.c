/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:22:31 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/11 15:31:43 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	char test_chars[] = {'a', 'Z', '5', '!', ' ',
					//  '\n', 'b', '1', 'G', '*', '0'};
// 	int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);
// 	int i = 0;
// 	while (i < num_tests)
// 	{
// 		char ch = test_chars[i];
// 		int result = ft_isascii(ch);

// 		if (result)
// 			printf("Character '%c' is ascii.\n", ch);
// 		else 
// 			printf("Character '%c' is not ascii.\n", ch);
// 		i++;
// 	}
// 	return (0);
// }