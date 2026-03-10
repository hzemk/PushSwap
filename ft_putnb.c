/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 23:06:37 by hal-taha          #+#    #+#             */
/*   Updated: 2025/12/29 15:31:57 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int x)
{
	int		i;
	long	nb;

	nb = x;
	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		i++;
	}
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar(nb % 10 + '0');
	return (i);
}

int	ft_putunsigned(unsigned int x)
{
	unsigned int	nb;
	int				i;

	nb = x;
	i = 0;
	if (nb > 9)
		i += ft_putunsigned(nb / 10);
	i += ft_putchar(nb % 10 + '0');
	return (i);
}

int	ft_putptr(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex(n, 'x');
	return (count);
}

int	ft_pute(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_float(double x)
{
	double		i;
	long int	nb;
	double		frac;

	nb = (long int)x;
	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		x = -x;
		i++;
	}
	if (nb > 9)
		i += ft_float(nb / 10);
	i += ft_putchar(nb % 10 + '0');
	frac = x - (long int)x;
	if (frac > 0)
	{
		i += ft_putchar('.');
		frac *= 100;
		i += ft_putchar(((int)frac / 10) + '0');
		i += ft_putchar(((int)frac % 10) + '0');
	}
	return (i);
}
