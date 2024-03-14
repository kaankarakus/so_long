/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:34:37 by kkarakus          #+#    #+#             */
/*   Updated: 2023/10/16 12:47:20 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!str)
		return (NULL);
	ft_bzero(str, (ft_strlen(s1) + ft_strlen(s2) + 1));
	ft_strlcat(str, s1, (ft_strlen(s1) + 1));
	ft_strlcat(str, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (str);
}
