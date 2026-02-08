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

void simple(t_stack *a)
{
	t_stack	*b;

	b = malloc (sizeof(t_stack));
	if (!b)
		return ;
	b->size = 0;
	b->head = NULL;
	while (a->size)
	{
		if (find_min(a) == find_top(a))
			pb(a,b);
		else
			ra(a);
	}
	while (b->size)
	{
		pa(a,b);
	}
	free(b);
}
