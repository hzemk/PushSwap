#include "pushswap.h"

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
	{
		ft_printf("rra\n");
		a->bench->rra++;
	}
}

void	rrb(t_stack *b)
{
	if (reverse_rotate(b))
	{
		ft_printf("rrb\n");
		b->bench->rrb++;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && b->size >= 2)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		ft_printf("rrr\n");
		a->bench->rrr++;
	}
}
