/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:41:46 by hal-taha          #+#    #+#             */
/*   Updated: 2026/02/09 19:12:13 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSHSWAP_H"

static int push(t_stack **src, t_stack **dst)
{
    t_stack *tmp;

    if (!src || !*src)
        return (0);
    tmp = (*src)->next;
    (*src)->next = *dst;
    *dst = *src;
    *src = tmp;
    return (1);
}

void pa(t_stack **a, t_stack **b)
{
    if (push(b, a))
    {
	ft_printf("%s","pa\n");
	a -> size++;
    	b -> size--;
    }
}

void pb(t_stack **a, t_stack **b)
{
    if (push(a, b))
    {
	    ft_printf("%s","pb\n");
	    a -> size--;
	    b -> size++;
    }
}
