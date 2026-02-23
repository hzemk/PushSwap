#include "pushswap.h"

void	bench(t_stack *a, t_stack *b)
{
	printf("[bench] disorder: %d%% %c ", (a->bench->disorder * 100), '\n');
	printf("[bench] strategy: %c", check_flag(), '\n');
	sum_bench(a, b);
	op_calc(a);
	printf("%%%c", '\n');
}

void	op_calc(t_stack *a)
{
	int	pa;
	int	pb;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
	int	count;

	pa = a->bench->pa;
	pb = a->bench->pb;
	ra = a->bench->ra;
	rra = a->bench->rra;
	rb = a->bench->rb;
	rrb = a->bench->rrb;
	rr = a->bench->rr;
	rrr = a->bench->rrr;
	sa = a->bench->sa;
	sb = a->bench->sb;
	ss = a->bench->ss;
	count = a->bench->count;
	ft_printf("[bench] total: %d", count);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d", sa, sb, ss, pa, pb);
	ft_printf("[bench] ra:%d rb: %d rr:%d rra: %d rrb: %d rrr: %d", ra, rb, rr,
		rra, rrb, rrr);
}

void	sum_bench(t_stack *a, t_stack *b)
{
	a->bench->rb = b->bench->rb;
	a->bench->sb = b->bench->sb;
	a->bench->rrb = b->bench->rrb;
	a->bench->count = a->bench->count + b->bench->count;
}
