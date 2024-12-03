/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:07:49 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/13 13:45:00 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
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
// 		int result = ft_isalnum(ch);

// 		if (result)
// 			printf("Character '%c' is alphanumeric.\n", ch);
// 		else 
// 			printf("Character '%c' is not alphanumeric.\n", ch);
// 		i++;
// 	}
// 	return (0);
// }

/*
-the num_test is used to stor the number of chars int the test_chars[] array.
-then we go trough all of them, one by one.
*/
