/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:10:04 by hal-taha          #+#    #+#             */
/*   Updated: 2026/02/16 15:48:19 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = parsing(argc, argv);
	b = malloc(sizeof(t_stack));
	if (!b)
		return (0);
	b->top = NULL;
	b->size = 0;
	if (!is_sorted(a))
		chunk_based(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
