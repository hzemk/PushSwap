/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobeida <leobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 13:13:08 by leobeida          #+#    #+#             */
/*   Updated: 2026/03/30 02:04:30 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	adaptive(t_stack *a, t_stack *b)
{
	double	dis;

	if (a->size <= 5)
	{
		simple(a);
		return ;
	}
	dis = disorder(a);
	if (dis < 0.2)
		simple(a);
	else if (dis < 0.5)
		medium(a, b);
	else
		complex_sort(a, b);
}
