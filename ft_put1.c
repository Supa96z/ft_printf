/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:41:39 by abataill          #+#    #+#             */
/*   Updated: 2022/11/19 04:42:13 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	sizenbr(long long n, int size, int stat)
{
	if (stat == -1)
		return (-1);
	while (n > 9 && ++size)
		n /= 10;
	return (size + 1);
}

int	ft_putnbr(long long nb)
{
	int			size;
	static int	stat;

	size = 0;
	stat = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		size++;
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	if (!stat && write(1, &"0123456789"[nb % 10], 1) == -1)
		stat = -1;
	return (sizenbr(nb, size, stat));
}

int	ft_putunbr(unsigned long nb)
{
	int			size;
	static int	stat;

	size = 0;
	stat = 0;
	if (nb > 9)
		ft_putunbr(nb / 10);
	if (!stat && write(1, &"0123456789"[nb % 10], 1) == -1)
		stat = -1;
	return (sizenbr(nb, size, stat));
}

int	ft_putstr(char *s)
{
	int	size;

	size = -1;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[++size])
		if (write(1, &s[size], 1) == -1)
			return (-1);
	return (size);
}
