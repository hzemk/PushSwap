/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:42:36 by hal-taha          #+#    #+#             */
/*   Updated: 2026/02/08 15:47:28 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_top(t_stack *a)
{
	int	i;

	i = 1;
	while (i < a->size)
	{
		a = a->next;
		i++;
	}
	return(a-> value);
}
int strcmp(char *s, char *j)
{
        int i;

        i=0;
        if(!s)
                return (NULL);
        while(s[i] && j[i] && s[i] == j[i])
                i++;
        return (s[i] - j[i]);

}
