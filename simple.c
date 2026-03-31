/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:56:07 by hal-taha          #+#    #+#             */
/*   Updated: 2026/04/01 00:23:04 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_stack	*init_local_b(void)
{
	t_stack	*b;

	b = init_stack();
	if (!b)
		return (NULL);
	b->bench = malloc(sizeof(t_bench));
	if (!b->bench)
		return (free(b), NULL);
	init_bs(b);
	return (b);
}

static void	free_local_b(t_stack *b)
{
	if (!b)
		return ;
	free(b->bench);
	free_nodes(b);
	free(b);
}

void	simple_five(t_stack *a, t_stack *b)
{
	if (a->size == 4 || a->size == 5)
	{
		while (a->size > 3)
		{
			if (a->top->value == find_min(a))
				pb(a, b);
			else
				ra(a);
		}
		if (a->top->value > a->top->next->value)
			sa(a);
		if (!is_sorted(a))
		{
			rra(a);
			if (a->top->value > a->top->next->value)
				sa(a);
		}
		while (b->size)
			pa(a, b);
	}
	if (a->size == 2 && (a->top->value > a->top->next->value))
		sa(a);
	if (a->size == 3)
		sort_three(a);
}

static void	move_min_to_top(t_stack *a)
{
	int	min;
	int	index;

	min = find_min(a);
	index = find_index(a, min);
	if (index <= a->size / 2)
	{
		while (find_top(a) != min)
			ra(a);
	}
	else
	{
		while (find_top(a) != min)
			rra(a);
	}
}

void	simple(t_stack *a)
{
	t_stack	*b;

	if (!a || a->size < 2)
		return ;
	b = init_local_b();
	if (!b)
		return ;
	if (a->size <= 5)
	{
		simple_five(a, b);
		free_local_b(b);
		return ;
	}
	while (a->size > 0)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
	free_local_b(b);
}
