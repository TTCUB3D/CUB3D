/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:02:14 by tursescu          #+#    #+#             */
/*   Updated: 2024/08/06 13:05:30 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_pr(long n)
{
	unsigned int	len;

	len = num_len(n);
	if (n < 0)
	{
		ft_putchar_pr('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_pr(n / 10);
	ft_putchar_pr((n % 10) + 48);
	return (len);
}
