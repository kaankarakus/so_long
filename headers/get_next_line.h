/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:28:12 by kkarakus          #+#    #+#             */
/*   Updated: 2024/03/08 15:17:00 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "unistd.h"
# include "stdlib.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	*ft_gnl_strchr(char *s, int c);
char	*ft_gnl_strjoin(char *left_str, char *buff);

size_t	ft_gnllen(const char *s);

#endif