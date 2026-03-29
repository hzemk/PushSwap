/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:41:46 by hal-taha          #+#    #+#             */
/*   Updated: 2026/03/29 23:12:40 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	push(t_stack *src, t_stack *dst)
{
	t_node	*moved;

	if (!src || !src->top)
		return (0);
	moved = src->top;
	src->top = moved->next;
	moved->next = dst->top;
	dst->top = moved;
	src->size--;
	dst->size++;
	return (1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push(b, a))
	{
		write(1, "pa\n", 3);
		a->bench->pa++;
		a->bench->count++;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (push(a, b))
	{
		write(1, "pb\n", 3);
		a->bench->pb++;
		a->bench->count++;
	}
}
