/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:11:06 by hal-taha          #+#    #+#             */
/*   Updated: 2026/03/10 15:14:49 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	


void	pick_algo(char *arg , double dis)
{
	if (ft_strcmp(arg, "--simple") == 0)
		ft_printf("Simple /  O(n2)");
	if (ft_strcmp(arg, "--medium") == 0)
		ft_printf("Medium / O(n√n)");
	if (ft_strcmp(arg, "--complex") == 0)
		ft_printf("Complex / O(nlog(n))");
	else
	{
		if (dis < 0.2)
			ft_printf("Adaptive /  O(n2)");
		else if (dis >= 0.2 && dis < 0.5)
			ft_printf("Adaptive / O(n√n)");
		else
			ft_printf("Adaptive / O(nlog(n))");
	}
}
