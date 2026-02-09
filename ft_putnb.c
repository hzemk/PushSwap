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
