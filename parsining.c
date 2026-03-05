/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsining.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:02:52 by hal-taha          #+#    #+#             */
/*   Updated: 2026/02/08 14:27:15 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->top)
	{
		tmp = stack->top;
		stack->top = tmp->next;
		free(tmp);
	}
	free(stack);
}

void	error(t_stack *a)
{
	free_stack(a);
	ft_printf("%e", "Error\n");
	exit(1);
}

t_stack	*parsing(int argc, char **argv)
{
	t_stack	*a;
	long	num;
	int		i;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->top = NULL;
	a->size = 0;
	a->bench = NULL;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			i++;
			continue;
		}
		if (!is_number(argv[i]))
			error(a);
		num = ft_atoi(argv[i]);
		if (out_of_range(num) || is_dup(a, num))
			error(a);
		push_back(a, (int)num);
		i++;
	}
	if (a->size == 0)
		error(a);
	return (a);
}
