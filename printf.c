/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:52:41 by hal-taha          #+#    #+#             */
/*   Updated: 2026/03/18 13:34:54 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	return (write(2, &c, 1));
}

int	ft_puthex(unsigned long nbr, char spec)
{
	int		i;
	char	*base;

	i = 0;
	if (spec == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr >= 16)
		i += ft_puthex(nbr / 16, spec);
	i += ft_putchar(base[nbr % 16]);
	return (i);
}

static int	handle_format(char spec, va_list args)
{
	if (spec == 'e')
		return (ft_pute(va_arg(args, char *)));
	if (spec == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (spec == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	if (spec == 'x' || spec == 'X')
		return (ft_puthex(va_arg(args, unsigned int), spec));
	if (spec == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	if (spec == '%')
		return (ft_putchar('%'));
	if (spec == 'f')
		return (ft_float(va_arg(args, double)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += handle_format(*format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
