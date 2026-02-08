#include "PUSHSWAP_H"

static int swap(t_stack *s)
{
    int tmp;

    if (!s || !s->next)
        return (0);
    tmp = s->value;
    s->value = s->next->value;
    s->next->value = tmp;
    return (1);
}

void sa(t_stack **s)
{
    if (swap(*s))
        putstr("sa\n");
}

void sb(t_stack **s)
{
    if (swap(*s))
        putstr("sb\n");
}

void ss(t_stack **a, t_stack **b)
{
    if (swap(*a) | swap(*b))
        putstr("ss\n");
}
