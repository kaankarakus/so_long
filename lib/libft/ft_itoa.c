/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:05:57 by kkarakus          #+#    #+#             */
/*   Updated: 2023/10/24 09:31:47 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(int n)
{
	int	j;

	j = 0;
	if (n < 0)
	{
		n *= -1;
		j++;
	}
	while (n > 0)
	{
		n /= 10;
		j++;
	}
	return (j);
}

static char	*check(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup("-2147483648"));
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0 || n == -2147483648)
		return (check(n));
	len = ft_digits(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len--] = '\0';
	while (n > 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}
