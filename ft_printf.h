/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:47:19 by abataill          #+#    #+#             */
/*   Updated: 2022/11/19 03:31:18 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putaddr(unsigned long ptr, char *base);
int	ft_putnbr_base(unsigned int nb, char *base);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putunbr(unsigned long nb);
int	ft_putnbr(long long nb);

#endif
