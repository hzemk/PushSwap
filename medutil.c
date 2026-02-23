/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:15:06 by hal-taha          #+#    #+#             */
/*   Updated: 2026/02/16 15:43:12 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*stack_toarr(t_stack *a)
{
	int		n;
	int		*arr;
	t_node	*node;
	int		i;

	n = a->size;
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return (0);
	node = a->top;
	i = 0;
	while (node)
	{
		arr[i] = node->value;
		i++;
		node = node->next;
	}
	return (arr);
}

void	sort_arr(int *arr, int n)
{
	int	min;
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < (n - i - 1))
		{
			if (arr[j] > arr[j + 1])
			{
				min = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = min;
			}
			j++;
		}
		i++;
	}
}
t_chunk	*create_chunks(int *sorted, int chunk_count, int n)
{
	t_chunk	*chunks;
	int		len;
	int		i;

	chunks = malloc(sizeof(t_chunk) * chunk_count);
	if (!chunks)
		return (0);
	len = n / chunk_count;
	i = 0;
	while (i < chunk_count)
	{
		chunks[i].min = sorted[i * len];
		if (i == (chunk_count - 1))
			chunks[i].max = sorted[n - 1];
		else
			chunks[i].max = sorted[(i + 1) * len - 1];
		i++;
	}
	return (chunks);
}

int	count_chunks(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}
void	push_toB(t_stack *a, t_stack *b, t_chunk *chunk)
{
	int	size;
	int	i;
	int	head;

	if (!a || !a->top)
		return ;
	i = 0;
	size = a->size;
	while (i < size)
	{
		if (!a->top)
			break ;
		head = a->top->value;
		if (head >= chunk->min && head <= chunk->max)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

void	push_toA(t_stack *a, t_stack *b)
{
	int	maxi;

	while (b->size)
	{
		maxi = find_max(b);
		while (b->top->value != maxi)
		{
			if (find_index(b, maxi) <= (b->size / 2))
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}
