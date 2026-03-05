#include "pushswap.h"

t_stack	*init_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->top = NULL;
	new->bench = NULL;
	new->size = 0;
	return (new);
}

void	free_nodes(t_stack *s)
{
	t_node	*tmp;

	while (s->size)
	{
		tmp = s->top->next;
		free(s->top);
		s->top = tmp;
		s->size--;
	}
}

void	free_all(t_stack *a, t_stack *b)
{
	free(a->bench);
	free_nodes(a);
	free(a);
	free(b->bench);
	free_nodes(b);
	free(b);
}
