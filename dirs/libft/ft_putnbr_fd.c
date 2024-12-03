/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:11:49 by tursescu          #+#    #+#             */
/*   Updated: 2024/08/06 12:55:05 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
// #include <stdio.h>
// int main(void)
// {
// 	ft_putnbr_fd(-2147483648, 1);
// 	printf("\n");
// 	ft_putnbr_fd(-502, 1);
// 	printf("\n");
// 	ft_putnbr_fd(6704, 1);
// 	printf("\n");
// 	ft_putnbr_fd(0, 1);
// 	printf("\n");
// 	return (0);
// }fd_putchar_fd(putbmbr)