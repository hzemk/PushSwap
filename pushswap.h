#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

/*
** Node structure (one element in the stack)
*/
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

/*
** Stack container
** top points to the TOP of the stack
*/
typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

/*
 Push operations
*/
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

/*
** Swap operations
*/
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

/*
** Rotate operations
*/
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

/*
 * Reverse rotate operations
 */
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

/*
** Parsing / validation
*/
int					is_number(char *str);
long				ft_atoi(const char *nptr);
int					out_of_range(long num);
int					is_dup(t_stack *a, long num);

/*
** Stack utilities
*/
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);
int					find_index(t_stack *stack, int value);
int					is_sorted(t_stack *stack);
int					find_top(t_stack *stack);
int					find_bottom(t_stack *stack);

/*
 * Stack creation / helpers
 */
void				push_back(t_stack *stack, int value);
t_stack				*parsing(int argc, char **argv);

#endif
