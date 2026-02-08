/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:29:42 by hal-taha          #+#    #+#             */
/*   Updated: 2026/02/08 14:55:22 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int is_number(char *str)
{
    int i;

    if (!str || str[0] == '\0')
        return (0);

    i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;

    if (str[i] == '\0')
        return (0);

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

long     ft_atoi(const char *nptr)
{
        int     i;
        int     sign;
        long     result;

        i = 0;
        result = 0;
        sign = 1;
        while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
                i++;
        if (nptr[i] == '-' || nptr[i] == '+')
        {if (nptr[i] == '-')
                        sign = -1;
                i++;
        }
        while (nptr[i] <= '9' && nptr[i] >= '0')
        {
                result = result * 10 + (nptr[i] - '0');
                i++;
        }
        return ((long)(sign * result));
}

int     out_of_range(long num)
{
        int i;
        i =0;
        if (num <= -2147483648L || num >= 2147483648L)
                return (0);
        return (1);
}

int    *is_dup(t_stack *a, long num)
{
	t_list	node;

	node = a->head;
	while (node)
	{
		if (node->content == num)
			return (0);
		node = node->next;
	}
	return (1);
}
