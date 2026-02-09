/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:30:48 by hal-taha          #+#    #+#             */
/*   Updated: 2026/02/09 20:13:32 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int find_min(t_stack *node)
{

        int	min;

        if (!node)
                return (0);
        min = node->value;
        while (node)
        {
                if (node->value < min)
                        min = node->value;
                node = node->next;
        }
        return (min);
}

int find_max(t_stack *node)
{

        int max;

        if(!node)
                return (0);
        max= node->value;
        while(node)
        {
                if(node->value > max)
                        max=node->value;
                node=node->next;
        }
        return (max);
}int is_sorted(t_stack *node)
{
        if(!node || !node->next)
                return (0);
        while(node->next)
        {
                if(node->value > node->next->value)
                        return(0);
                node=node->next
        }
        return (1);
}

int find_index(t_stack *a, int value)
{
        int i

        i = 0;
        while(a)
        {
                if(a->value > value)
                        return (i);
                a=a->next;
                i++;
        }
        return (-1);
}

int size_stack(t_stack *a)
{
        int count;

        count=0;
        while(a)
        {
                count++;
                a= a->next;
        }
        return(count);
}
