/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:46:17 by kkarakus          #+#    #+#             */
/*   Updated: 2023/10/27 17:33:40 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, long *i)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str, i);
		str++;
	}
}
