/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:11:06 by hal-taha          #+#    #+#             */
/*   Updated: 2026/03/15 11:21:08 by leobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
void	pick_algo(char *arg , char *argv, double dis)
{
	if (ft_strcmp(arg, "--simple") == 0 || ft_strcmp(argv, "--simple") == 0)
		ft_printf("Simple /  O(n2)");
	if (ft_strcmp(arg, "--medium") == 0 || ft_strcmp(argv, "--medium") == 0)
		ft_printf("Medium / O(n√n)");
	if (ft_strcmp(arg, "--complex") == 0 || ft_strcmp(argv, "--complex") == 0)
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
}*/
char	*pick_algo(char *arg, char *argv, double dis)
{
	if (ft_strcmp(arg, "--simple") == 0 || ft_strcmp(argv, "--simple") == 0)
		return ("Simple /  O(n2)");
	if (ft_strcmp(arg, "--medium") == 0 || ft_strcmp(argv, "--medium") == 0)
		return ("Medium / O(n√n)");
	if (ft_strcmp(arg, "--complex") == 0 || ft_strcmp(argv, "--complex") == 0)
		return ("Complex / O(nlog(n))");
	else
	{
		if (dis < 0.2)
			return ("Adaptive /  O(n2)");
		else if (dis >= 0.2 && dis < 0.5)
			return ("Adaptive / O(n√n)");
		else
			return ("Adaptive / O(nlog(n))");
	}
}
