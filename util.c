/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:42:36 by hal-taha          #+#    #+#             */
/*   Updated: 2026/03/18 13:16:17 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_bottom(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current->next)
		current = current->next;
	return (current->value);
}

int	find_top(t_stack *stack)
{
	if (!stack || !stack->top)
		return (0);
	return (stack->top->value);
}

void	push_back(t_stack *a, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->next = a->top;
	a->top = new;
	a->size++;
}

/*
void	push_back(t_stack *stack, int value)
{
	t_node	*new;
	t_node	*current;

	if (!stack)
		return ;
	new = malloc(sizeof(t_node));
	if (!new)
		error(stack);
	new->value = value;
	new->next = NULL;
	if (!stack->top)
		stack->top = new;
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	stack->size++;
}
*/
int	ft_strcmp(char *s, char *j)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && j[i] && s[i] == j[i])
		i++;
	return (s[i] - j[i]);
}
