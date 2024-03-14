/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:52:53 by kkarakus          #+#    #+#             */
/*   Updated: 2023/10/30 10:55:45 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type(char c, va_list *arg, long *i)
{
	if (c == 'c')
		ft_putchar(va_arg(*arg, int), i);
	else if (c == 's')
		ft_putstr(va_arg(*arg, char *), i);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*arg, int), i);
	else if (c == 'p')
	{
		ft_putstr("0x", i);
		ft_dectohex(va_arg(*arg, unsigned long), c, i);
	}
	else if (c == 'u')
		ft_putunbr(va_arg(*arg, unsigned int), i);
	else if (c == 'x' || c == 'X')
		ft_dectohex(va_arg(*arg, unsigned int), c, i);
	else
		ft_putchar(c, i);
}

int	ft_printf(const char *str, ...)
{
	long	i;
	va_list	arg;

	i = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			type(*(++str), &arg, &i);
			str++;
		}
		else
		{
			ft_putchar(*str, &i);
			str++;
		}
	}
	va_end(arg);
	return (i);
}
