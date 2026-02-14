/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:56:07 by hal-taha          #+#    #+#             */
/*   Updated: 2026/02/08 16:06:04 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	while (a->size > 0)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
	free(b);
}
