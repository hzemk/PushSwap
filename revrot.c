#include "PUSHSWAP_H"

int revrot(t_stack **s)
{
    t_stack *prev;
    t_stack *last;

    if (!s || !*s || !(*s)->next)
        return (0);

    prev = NULL;
    last = *s;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;
    last->next = *s;
    *s = last;

    return (1);
}

void    rra(t_stack **sa)
{
    if (revrot(sa))
        putstr("rra\n");
}

void    rrb(t_stack **sb)
{
    if (revrot(sb))
        putstr("rrb\n");
}

void    rrr(t_stack **sa, t_stack **sb)
{
    if (revrot(sa) | revrot(sb))
        putstr("rrr\n");
}
