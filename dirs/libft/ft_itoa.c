/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:10:40 by tursescu          #+#    #+#             */
/*   Updated: 2024/06/24 12:50:12 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

unsigned int	int_length(int nb)
{
	unsigned int	len;

	len = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	unsigned int	len;

	len = int_length(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)n;
	if (n == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}
/*
-23 we check for negative no so we increment length by one for the "-";
- once we've got the length of the int we can malloc properly;
-43 we go to the back of the string and declare the null terminator,
the reason why we do this first is because later on in the while loop(53),
we will iterate trough all the indexes of str, by decrementing len;
- 55 we predecrement so we can first get off the position of '\0',
then we go trough every index and by adding '0'/48 we recieve the ascii val
of the char with the same form (so 9 becomes '9');
*/

// int	main(void)
// {
// 	char	*str;
// 	int		n;

// 	n = -242323;
// 	str = ft_itoa(n);
// 	printf("%s\n", str);
// 	return (0);
// }
