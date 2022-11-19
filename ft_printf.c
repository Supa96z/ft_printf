/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:45:06 by abataill          #+#    #+#             */
/*   Updated: 2022/11/19 04:39:19 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_type(char c, va_list ap)
{
	int	size;

	size = -1;
	if (c == 'c')
		size = ft_putchar(va_arg(ap, int));
	else if (c == 's')
		size = ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		size = ft_putaddr(va_arg(ap, unsigned long), "0123456789abcdef");
	else if (c == 'd' || c == 'i')
		size = ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		size = ft_putunbr(va_arg(ap, unsigned int));
	else if (c == 'x')
		size = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		size = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		size = ft_putchar('%');
	if (size == -1)
		size = -2147483648;
	return (size);
}

int	putfm(char c)
{
	if (write(1, &c, 1) == -1)
		return (-2147483648);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		size;

	i = -1;
	size = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
			size += ft_type(format[++i], ap);
		else
			size += putfm(format[i]);
		if (size < 0)
			return (-1);
	}
	va_end(ap);
	return (size);
}
