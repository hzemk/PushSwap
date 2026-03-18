/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
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

static int	skip_flags(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
		i++;
	return (i);
}

static void	parse_arg(t_stack *a, char *arg)
{
	int		i;
	long	num;

	i = 0;
	while (arg[i])
	{
		while (arg[i] == ' ')
			i++;
		if (!arg[i])
			break ;
		if (!is_number(&arg[i]))
			error(a);
		num = ft_atoi(&arg[i]);
		if (out_of_range(num) || is_dup(a, num))
			error(a);
		push_back(a, (int)num);
		while (arg[i] && arg[i] != ' ')
			i++;
	}
}

t_stack	*parsing(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = init_stack();
	if (!a)
		return (NULL);
	i = skip_flags(argv, argc);
	while (i < argc)
	{
		parse_arg(a, argv[i]);
		i++;
	}
	if (a->size == 0)
		error(a);
	return (a);
}
