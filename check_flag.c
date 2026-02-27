/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 00:00:00 by hal-taha          #+#    #+#             */
/*   Updated: 2026/02/27 00:00:00 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_algo(char *arg)
{
	if (strcmp(arg, "--simple") == 0)
		return (MODE_SIMPLE);
	if (strcmp(arg, "--medium") == 0)
		return (MODE_MEDIUM);
	if (strcmp(arg, "--complex") == 0)
		return (MODE_COMPLEX);
	return (MODE_ERROR);
}

static int	parse_flags(char **argv, int argc, int i)
{
	int	algo;
	int	bench;
	int	tmp;

	algo = MODE_ADAPTIVE;
	bench = 0;
	while (i < argc)
	{
		if (strcmp(argv[i], "--bench") == 0)
			bench = 1;
		else
		{
			tmp = get_algo(argv[i]);
			if (tmp == MODE_ERROR || algo != MODE_ADAPTIVE)
				return (MODE_ERROR);
			algo = tmp;
		}
		i++;
	}
	if (bench)
		return (algo + 10);
	return (algo);
}

int	check_flag(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc && is_number(argv[i]))
		i++;
	return (parse_flags(argv, argc, i));
}
