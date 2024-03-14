/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:25:45 by kkarakus          #+#    #+#             */
/*   Updated: 2023/10/27 17:33:40 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int n, long *i)
{
	if (n > 9)
		ft_putunbr(n / 10, i);
	ft_putchar((n % 10) + '0', i);
}
