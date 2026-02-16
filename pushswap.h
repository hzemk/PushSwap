#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

typedef struct s_chunk
{
    int min;
    int max;
}       t_chunk;

/* Push */
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

/* Swap */
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

/* Rotate */
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

/* Reverse Rotate */
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

/* Parsing */
int					is_number(char *str);
long				ft_atoi(const char *nptr);
int					out_of_range(long num);
int					is_dup(t_stack *a, long num);
t_stack				*parsing(int argc, char **argv);

/* Stack utils */
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);
int					find_index(t_stack *stack, int value);
int					is_sorted(t_stack *stack);
int					find_top(t_stack *stack);
int					find_bottom(t_stack *stack);
void				push_back(t_stack *stack, int value);

/* Memory */
void				free_stack(t_stack *stack);
void				error(t_stack *a);

/* algos */
void				simple(t_stack *a);
#endif
