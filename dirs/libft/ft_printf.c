/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:17:57 by tursescu          #+#    #+#             */
/*   Updated: 2024/08/06 13:00:34 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	what_format(const char *string, int i, va_list args)
{
	int	length;

	length = 0;
	if (string[i] == 'd' || string[i] == 'i')
		length += ft_putnbr_pr(va_arg(args, int));
	else if (string[i] == 's')
		length += ft_putstr_pr(va_arg(args, char *));
	else if (string[i] == 'c')
		length += ft_putchar_pr((char)va_arg(args, int));
	else if (string[i] == 'x')
		length += ft_puthex_pr(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (string[i] == 'X')
		length += ft_puthex_pr(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (string[i] == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (string[i] == 'p')
		length += ft_putptr_pr(va_arg(args, void *));
	else if (string[i] == '%')
		length += ft_putchar_pr('%');
	else
		length += ft_putchar_pr('%');
	return (length);
}

int	ft_printf(const char *string, ...)
{
	int				length;
	int				i;
	va_list			args;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i] == '\0')
				break ;
			length += what_format(string, i, args);
		}
		else
			length += ft_putchar_pr(string[i]);
		i++;
	}
	va_end(args);
	return (length);
}

/*
- the else in the what_descritor function makes it so that the 
function just prints the '%' and whatever 
comes afterwards if what follows afte
*/