/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsining.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:02:52 by hal-taha          #+#    #+#             */
/*   Updated: 2026/02/08 14:27:15 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack	*parsing(int argc, char **argv)
{
	t_stack	*a;
	long	i;

	i = 1;
	a = malloc(sizeof t_stack);
	if (!a)
		return (NULL);
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			i++;
			continue ;
		}
		if (!isnum(argv[i]) || (outofrange(argv[i])) || isdup(a,
				ft_atoi(argv[i])))
		{
			ft_printf("%e", "Error\n");
			free(a);
			exit(0);
		}
		push_back(&a, ft_atoi(argv[i]));
	}
	return (a);
}
