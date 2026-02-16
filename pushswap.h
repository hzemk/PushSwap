#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
        int size;
        struct s_list   *head;
}               t_stack;

typedef struct s_chunk
{
	int min;
	int max;
}		t_chunk;

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
