#include "PUSHSWAP_H"

static int push(t_stack **src, t_stack **dst)
{
    t_stack *tmp;

    if (!src || !*src)
        return (0);
    tmp = (*src)->next;
    (*src)->next = *dst;
    *dst = *src;
    *src = tmp;
    return (1);
}

void pa(t_stack **a, t_stack **b)
{
    if (push(b, a))
        putstr("pa\n");
}

void pb(t_stack **a, t_stack **b)
{
    if (push(a, b))
        putstr("pb\n");
}
