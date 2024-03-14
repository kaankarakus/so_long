/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:39:44 by kkarakus          #+#    #+#             */
/*   Updated: 2023/10/30 10:22:59 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dectohex(unsigned long p, char c, long *i)
{
	char			*base;

	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (p > 15)
		ft_dectohex(p / 16, c, i);
	ft_putchar(base[p % 16], i);
}
