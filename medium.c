/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobeida <leobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:00:00 by leobeida          #+#    #+#             */
/*   Updated: 2026/02/16 11:00:39 by leobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void chunk_based(t_stack *a, t_stack *b)
{
	int n;
	int count;
	int *sorted;
	int i;

	n=a->size;
	count=count_chunks(n);
	sorted=stack_toarr(a);
	sort_arr(sorted, n);
	t_chunk *chunk;
	chunk=create_chunk(sorted, count, n);
	i=0;
	while(i < count)
	{
		push_toB(a, b, chunk);
	}
	pust_toA(a, b);

	free(sorted);
	free(chunk);
}
