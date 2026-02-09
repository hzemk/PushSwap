#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdlib.h>

typedef struct s_stack
{
	int				size;
	struct s_stack	*next;
}	t_stack;

int     rotate(t_stack **stack);
int     revrot(t_stack **stack);

void    ra(t_stack **sa);
void    rb(t_stack **sb);
void    rr(t_stack **sa, t_stack **sb);

void    rra(t_stack **sa);
void    rrb(t_stack **sb);
void    rrr(t_stack **sa, t_stack **sb);

void    sa(t_stack **sa);
void    sb(t_stack **sb);
void    ss(t_stack **sa, t_stack **sb);

void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);

#endif
