#include "PUSHSWAP_H"

static int	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || stack->size < 2)
		return (0);
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	return (1);
}

void	rra(t_stack *a)
{
	if (reverse_rotate(a))
		ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (reverse_rotate(b))
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	int	rotated;

	rotated = 0;
	if (reverse_rotate(a))
		rotated++;
	if (reverse_rotate(b))
		rotated++;
	if (rotated)
		ft_printf("rrr\n");
}
