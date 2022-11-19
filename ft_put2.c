/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:53:44 by abataill          #+#    #+#             */
/*   Updated: 2022/11/19 04:43:39 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sizenbrb(long nb, int size, int stat)
{
	if (stat == -1)
		return (-1);
	while (nb > 15 && ++size)
		nb /= 16;
	return (size + 1);
}

int	ft_putnbr_base(unsigned int nb, char *base)
{
	int			size;
	static int	stat;

	size = 0;
	stat = 0;
	if (nb > 15)
		ft_putnbr_base(nb / 16, base);
	if (!stat && write(1, &base[nb % 16], 1) == -1)
		stat = -1;
	return (sizenbrb(nb, size, stat));
}

int	sizeptr(unsigned long ptr, int size)
{
	if (ptr < 16 && ptr > 0)
		size++;
	while (ptr > 15 && size++)
		ptr /= 16;
	return (size + 1);
}

int	recurs(unsigned long ptr, char *base, int size)
{	
	if (ptr > 15)
		recurs(ptr / 16, base, size++);
	if (write(1, &base[ptr % 16], 1) == -1)
		return (-1);
	return (sizeptr(ptr, size));
}

int	ft_putaddr(unsigned long ptr, char *base)
{
	int	size;

	if (write(1, "0x", 2) == -1)
		return (-1);
	size = 1;
	if (!ptr)
		size++;
	return (recurs(ptr, base, size));
}
