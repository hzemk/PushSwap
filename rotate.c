/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:33:23 by hal-taha          #+#    #+#             */
/*   Updated: 2026/02/16 14:33:26 by hal-taha         ###   ########.fr       */
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
		ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	if (rotate(b))
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		rotate(a);
		rotate(b);
		ft_printf("rr\n");
	}
}
