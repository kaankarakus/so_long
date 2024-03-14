/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:45:23 by kkarakus          #+#    #+#             */
/*   Updated: 2023/10/16 16:15:34 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	checker(char c, char const *set)
{
	while (set && *set)
	{
		if (c == *set++)
			return (0);
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (checker(s1[start], set) == 0)
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (checker(s1[end - 1], set) == 0)
		end--;
	str = ft_substr(s1, start, end - start);
	return (str);
}
