/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:30:58 by thlibers          #+#    #+#             */
/*   Updated: 2025/11/11 11:47:57 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_putptr(void *p);
size_t	ft_putnbr(long n);
size_t	ft_putunbr(unsigned long n);
size_t	ft_puthex(unsigned long h, int b);

#endif