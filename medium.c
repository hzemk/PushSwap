/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobeida <leobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:00:00 by leobeida          #+#    #+#             */
/*   Updated: 2026/03/18 10:57:38 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	medium(t_stack *a, t_stack *b)
{
	int		n;
	int		count;
	int		*sorted;
	int		i;
	t_chunk	*chunk;

	n = a->size;
	if (n == 5 || n == 4)
	{
		simple_five(a, b);
		return ;
	}
	count = count_chunks(n);
	sorted = stack_toarr(a);
	sort_arr(sorted, n);
	chunk = create_chunks(sorted, count, n);
	i = 0;
	while (i < count)
	{
		push_toB(a, b, &chunk[i]);
		i++;
	}
	push_toA(a, b);
	free(sorted);
	free(chunk);
}
