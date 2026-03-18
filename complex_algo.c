/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:21:27 by hal-taha          #+#    #+#             */
/*   Updated: 2026/03/18 11:34:25 by leobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

static void	process_bits(t_stack *a, t_stack *b, int i)
{
	int	j;
	int	size;

	j = 0;
	size = a->size;
	while (j < size)
	{
		if (((a->top->value >> i) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		j++;
	}
	while (b->size > 0)
		pa(a, b);
}

void	complex_sort(t_stack *a, t_stack *b)
{
	int	*arr;
	int	i;
	int	bits;

	arr = stack_toarr(a);
	sort_arr(arr, a->size);
	bits = find_bits(a->size - 1);
	convert(a, arr);
	i = 0;
	while (i < bits)
	{
		process_bits(a, b, i);
		i++;
	}
	free(arr);
}

int	get_index(int *arr, int top, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (top == arr[i])
			return (i);
		i++;
	}
	return (-1);
}

t_stack	*convert(t_stack *a, int *arr)
{
	int		i;
	t_node	*node;

	i = 0;
	node = a->top;
	while (i < a->size)
	{
		node->value = get_index(arr, node->value, a->size);
		node = node->next;
		i++;
	}
	return (a);
}

int	find_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
