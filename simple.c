/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:56:07 by hal-taha          #+#    #+#             */
/*   Updated: 2026/03/18 10:57:57 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void simple_five(t_stack *a, t_stack *b)
{
	while (a->size != 3)
	{
		if (a->top->value == find_min(a))
			pb(a,b);
		else
			ra(a);
	}
	while (find_bottom(a) != find_min(a))
		rra(a);
	if (a->top > a->top->next)
		sa(a);
	pa(a,b);
	pa(a,b);
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
	b = malloc(sizeof(t_stack));
	if (!b)
		return ;
	b->top = NULL;
	b->size = 0;
	if (a->size == 5 || a->size == 4)
	{
		simple_five(a, b);
		return ;
	}
	while (a->size > 0)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
	free(b);
}
