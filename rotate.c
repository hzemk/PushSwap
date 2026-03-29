/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:33:23 by hal-taha          #+#    #+#             */
/*   Updated: 2026/03/29 23:13:23 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return (0);
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
	return (1);
}

void	ra(t_stack *a)
{
	if (rotate(a))
	{
		write(1, "ra\n", 3);
		a->bench->ra++;
		a->bench->count++;
	}
}

void	rb(t_stack *b)
{
	if (rotate(b))
	{
		write(1, "rb\n", 3);
		b->bench->rb++;
		b->bench->count++;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
		a->bench->rr++;
		a->bench->count++;
	}
}
