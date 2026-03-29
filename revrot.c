/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobeida <leobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:22:07 by leobeida          #+#    #+#             */
/*   Updated: 2026/03/29 23:12:59 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || stack->size < 2)
		return (0);
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	return (1);
}

void	rra(t_stack *a)
{
	if (reverse_rotate(a))
	{
		write(1, "rra\n", 4);
		a->bench->rra++;
		a->bench->count++;
	}
}

void	rrb(t_stack *b)
{
	if (reverse_rotate(b))
	{
		write(1, "rrb\n", 4);
		b->bench->rrb++;
		b->bench->count++;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write(1, "rrr\n", 4);
		a->bench->rrr++;
		a->bench->count++;
	}
}
