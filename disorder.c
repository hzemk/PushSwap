/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 00:00:00 by hal-taha          #+#    #+#             */
/*   Updated: 2026/02/27 00:00:00 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static double	calc_disorder(int *arr, int size)
{
	int	i;
	int	j;
	int	total;
	int	messy;

	i = 0;
	total = 0;
	messy = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				messy++;
			total++;
			j++;
		}
		i++;
	}
	return ((double)messy / total);
}

double	disorder(t_stack *a)
{
	int		*arr;
	double	result;

	if (!a || a->size < 2)
		return (0.0);
	arr = stack_toarr(a);
	if (!arr)
		return (0.0);
	result = calc_disorder(arr, a->size);
	free(arr);
	return (result);
}
