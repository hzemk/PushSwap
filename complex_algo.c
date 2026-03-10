/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:21:27 by hal-taha          #+#    #+#             */
/*   Updated: 2026/03/10 16:22:24 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



void	complex_sort(t_stack *a, t_stack *b)
{
	int	*arr;
	int	i;

	arr = malloc(a->size);
	arr = stack_toarr(a);
	sort_arr(arr, a->size);

	while()
	{
	}
}

int	get_index(int *arr, int top, int size)
{
	int i;

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
	int i;
	t_node *node;

	node = malloc (sizeof(t_node));
	i=0;
	node = a->top;
	while(i < a->size)
	{
		node->value = get_index(node->value);
		node = node->next;
		i++;
	}
	return (a);
}

int find_bits(int *arr ,int size)
{
	unsigned	index;
	int	couter;

	index = size - 1;
	counter = 0;
	while(index)
	{
		index /= 2;
		counter++;
	}
	return (counter - 1);
}

int convert_bit()
{

}
