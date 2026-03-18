/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobeida <leobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:00:00 by leobeida          #+#    #+#             */
/*   Updated: 2026/03/18 11:28:56 by leobeida         ###   ########.fr       */
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
		push_tob(a, b, &chunk[i]);
		i++;
	}
	push_toa(a, b);
	free(sorted);
	free(chunk);
}

t_chunk	*create_chunks(int *sorted, int chunk_count, int n)
{
	t_chunk	*chunks;
	int		len;
	int		i;

	chunks = malloc(sizeof(t_chunk) * chunk_count);
	if (!chunks)
		return (0);
	len = n / chunk_count;
	i = 0;
	while (i < chunk_count)
	{
		chunks[i].min = sorted[i * len];
		if (i == (chunk_count - 1))
			chunks[i].max = sorted[n - 1];
		else
			chunks[i].max = sorted[(i + 1) * len - 1];
		i++;
	}
	return (chunks);
}
