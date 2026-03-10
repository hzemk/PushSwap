/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 22:53:08 by hal-taha          #+#    #+#             */
/*   Updated: 2025/12/29 15:49:52 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_pute(char *str);
int	ft_putstr(char *str);
int	ft_printf(const char *format, ...);
int	ft_putnbr(int x);
int	ft_putunsigned(unsigned int x);
int	ft_putchar(char c);
int	ft_puthex(unsigned long nbr, char spec);
int	ft_putptr(unsigned long n);
int	ft_float(double x);
#endif
