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

static int	extract_mode(int mode, int *bench)
{
	*bench = 0;
	if (mode >= 10)
	{
		*bench = 1;
		mode -= 10;
	}
	return (mode);
}

static void	launch_algo(int mode, t_stack *a, t_stack *b)
{
	if (mode == MODE_ADAPTIVE)
		adaptive(a, b);
	else if (mode == MODE_SIMPLE)
		simple(a);
	else if (mode == MODE_MEDIUM)
		medium(a, b);
	else if (mode == MODE_COMPLEX)
		complex_sort(a, b);
}

void	print_stack(t_stack *stack)
{
	t_node	*cur;

	if (!stack)
		return ;
	cur = stack->top;
	ft_printf("Stack (%d): ", stack->size);
	while (cur)
	{
		ft_printf("%d ", cur->value);
		cur = cur->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		mode;
	int		bench1;

	if (argc < 2)
		return (0);
	mode = check_flag(argv, argc);
	if (mode == MODE_ERROR)
		return (ft_printf("%e", "Error\n"), 1);
	mode = extract_mode(mode, &bench1);
	a = parsing(argc, argv);
	b = init_stack();
	init_bench(a, b);
	a->bench->disorder = disorder(a);
	if (!is_sorted(a))
		launch_algo(mode, a, b);
	if (bench1)
	{
		sum_bench(a, b);
		bench(a);
	}
	print_stack(a);
	free_all(a, b);
	return (0);
}
