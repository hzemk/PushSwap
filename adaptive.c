/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobeida <leobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 13:13:08 by leobeida          #+#    #+#             */
/*   Updated: 2026/03/16 12:28:55 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	adaptive(t_stack *a, t_stack *b)
{
	double	dis;

	dis = disorder(a);
	if (dis < 0.2)
		simple(a);
	else if (dis >= 0.2 && dis < 0.5)
		medium(a, b);
	else
		complex_sort(a, b);
}
