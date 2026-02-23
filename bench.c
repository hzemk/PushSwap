#include "pushswap.h"

void bench(t_stack *a, t_stack *b)
{
	
	printf("[bench] disorder: %d%% %c ",(a->bench->disorder * 100), '\n');
	printf("[bench] strategy: %c", check_flag(), '\n');
	sum_bench(a, b);
	op_calc(a);
	printf("%%%c", '\n');
}

void op_calc(t_stack *a)
{
	int pa=a->bench->pa;
	int pb=a->bench->pb;
	int ra=a->bench->ra;
	int rra=a->bench->rra;
	int rb=a->bench->rb;
	int rrb=a->bench->rrb;
	int rr=a->bench->rr;
	int rrr=a->bench->rrr;
	int sa=a->bench->sa;
	int sb=a->bench->sb;
	int ss=a->bench->ss;
	int count=a->bench->count;

	ft_printf("[bench] total: %d", count);
    	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d", sa, sb, ss, pa, pb);
	ft_printf("[bench] ra:%d rb: %d rr:%d rra: %d rrb: %d rrr: %d", ra, rb, rr, rra, rrb, rrr);
}

void sum_bench (t_stack *a, t_stack *b)
{
        a->bench->rb = b->bench->rb;
        a->bench->pb = b->bench->pb;
        a->bench->sb = b->bench->sb;
        a->bench->rrb = b->bench->rrb;
        a->bench->count = a->bench->count + b->bench->count;
}
