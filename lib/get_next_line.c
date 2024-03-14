/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:03:19 by kkarakus          #+#    #+#             */
/*   Updated: 2024/03/08 15:18:43 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

char	*ft_read(char *str, int fd)
{
	char	*line;
	int		r;

	line = malloc((sizeof (char) * BUFFER_SIZE) + 1);
	if (!line)
		return (NULL);
	r = 1;
	while (!ft_gnl_strchr(str, '\n') && r != 0)
	{
		r = read(fd, line, BUFFER_SIZE);
		if (r == -1)
			return (free(line), free(str), NULL);
		line[r] = '\0';
		str = ft_gnl_strjoin(str, line);
		if (!str)
			return (free(line), NULL);
	}
	free(line);
	return (str);
}

char	*ft_line(char *str)
{
	int			i;
	char		*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = malloc((sizeof (char) * i) + 2);
	if (!line)
		return (free(str), NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_next_lines(char *str)
{
	char		*newstr;
	int			i;
	int			j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i])
		return (free(str), NULL);
	newstr = malloc((sizeof (char) * ft_gnllen(str) - i) + 1);
	if (!newstr)
		return (NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
		newstr[j++] = str[i++];
	newstr[j] = '\0';
	free(str);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_read(str, fd);
	if (str == NULL)
		return (NULL);
	line = ft_line(str);
	str = ft_next_lines(str);
	if (line == NULL)
		return (line);
	return (line);
}
