/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:13:36 by kkarakus          #+#    #+#             */
/*   Updated: 2023/10/14 17:15:33 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	str = malloc(sizeof (char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = *(s + start + i);
		i++;
	}
	str[i] = '\0';
	return (str);
}
