/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:35:46 by hal-taha          #+#    #+#             */
/*   Updated: 2026/02/16 12:26:24 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define MODE_ADAPTIVE -1
# define MODE_SIMPLE 1
# define MODE_MEDIUM 2
# define MODE_COMPLEX 3
# define MODE_ERROR -2

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_bench
{
	int				sa;
	int				ra;
	int				pb;
	int				pa;
	int				sb;
	int				rra;
	int				rrb;
	int				rrr;
	int				rb;
	int				rr;
	int				ss;
	double			disorder;
	int				count;
}					t_bench;

typedef struct s_stack
{
	t_node			*top;
	int				size;
	t_bench			*bench;
}					t_stack;

typedef struct s_chunk
{
	int				min;
	int				max;
}					t_chunk;

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
void				medium(t_stack *a, t_stack *b);
void				complex_sort(t_stack *a, t_stack *b);

/* chunk */

int					*stack_toarr(t_stack *a);
void				sort_arr(int *arr, int n);
t_chunk				*create_chunks(int *sorted, int chunk_count, int n);
int					count_chunks(int n);
void				push_toB(t_stack *a, t_stack *b, t_chunk *chunks);
void				push_toA(t_stack *a, t_stack *b);

/* flag */
int					check_flag(char **argv, int argc);

/* disorder || adaptive */
double				disorder(t_stack *a);
void				adaptive(t_stack *a, t_stack *b);

/*  initialization  */
t_stack				*init_stack(void);
void				init_bench(t_stack *a, t_stack *b);

/*  bench  */
void				print_bench(t_stack *a);
void				free_all(t_stack *a, t_stack *b);

void				select_strategy(t_stack *a, t_stack *b, char **argv,
						int argc);

int     strcmp(char *s, char *j);

#endif
