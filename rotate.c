#include "PUSHSWAP_H"

int	rotate(t_stack **stack)
{
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return(0);

    last = *stack;
    while (last->next)
        last = last->next;

    last->next = *stack;
    *stack = (*stack)->next;
    last->next->next = NULL;
    return (1);
}

void	ra(t_stack **sa)
{
	if (rotate(sa))
		putstr("ra\n");
}

void    rb(t_stack **sb)
{
        if (rotate(sb))
        	putstr("rb\n");
}

void	rr(t_stack **sa, t_stack **sb)
{
	if (rotate(sa) | rotate(sb))
		putstr("rr\n");
}
