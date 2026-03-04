#include "pushswap.h"

void	bench(t_stack *a)
{
	ft_printf("[bench] disorder: %.2f%%\n", a->bench->disorder * 100);
		// initialize %.2f
	ft_printf("[bench] total: %d\n", a->bench->count);
	ft_printf("[bench] sa:%d sb:%d ss:%d pa:%d pb:%d\n", a->bench->sa,
		a->bench->sb, a->bench->ss, a->bench->pa, a->bench->pb);
	ft_printf("[bench] ra:%d rb:%d rr:%d rra:%d rrb:%d rrr:%d\n", a->bench->ra,
		a->bench->rb, a->bench->rr, a->bench->rra, a->bench->rrb,
		a->bench->rrr);
}

void                            init_bench(t_stack *a, t_stack *b)
{
	init_bs(a);
	init_bs(b);
}

static void	init_bs(t_stack *a)
{
	a->bench->pa = 0;
	a->bench->pb = 0;
	a->bench->ra = 0;
	a->bench->rra = 0;
	a->bench->rb = 0;
	a->bench->rrb = 0;
	a->bench->rr = 0;
	a->bench->rrr = 0;
	a->bench->sa = 0;
	a->bench->sb = 0;
	a->bench->ss = 0;
	a->bench->count = 0;
}

void	sum_bench(t_stack *a, t_stack *b)
{
	a->bench->rb = b->bench->rb;
	a->bench->sb = b->bench->sb;
	a->bench->rrb = b->bench->rrb;
	a->bench->count = a->bench->count + b->bench->count;
}
