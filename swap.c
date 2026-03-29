/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobeida <leobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:22:23 by leobeida          #+#    #+#             */
/*   Updated: 2026/03/29 23:12:16 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	swap(t_stack *stack)
{
	int		tmp;
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	return (1);
}

void	sa(t_stack *a)
{
	if (swap(a))
	{
		write(1, "sa\n", 3);
		a->bench->sa++;
		a->bench->count++;
	}
}

void	sb(t_stack *b)
{
	if (swap(b))
	{
		write(1, "sb\n", 3);
		b->bench->sb++;
		b->bench->count++;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
		a->bench->count++;
		a->bench->ss++;
	}
}
