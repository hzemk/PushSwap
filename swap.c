#include "PUSHSWAP_H"

static int	swap(t_stack *stack)
{
	int		tmp;
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	return (1);
}

void	sa(t_stack *a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	swapped;

	swapped = 0;
	if (swap(a))
		swapped++;
	if (swap(b))
		swapped++;
	if (swapped)
		ft_printf("ss\n");
}
