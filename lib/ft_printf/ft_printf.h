/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:09:49 by kkarakus          #+#    #+#             */
/*   Updated: 2023/10/30 10:23:13 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "unistd.h"
# include "stdarg.h"

int		ft_printf(const char *str, ...);

void	ft_putchar(char c, long *i);
void	ft_putstr(char *str, long *i);
void	ft_dectohex(unsigned long p, char c, long *i);
void	ft_putnbr(int n, long *i);
void	ft_putunbr(unsigned int n, long *i);

#endif
