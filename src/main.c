/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 09:50:11 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/23 12:03:00 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_args(&a, ac, av))
	{
		print_error();
		free_stack(&a);
		return (1);
	}
	if (is_sorted(a))
		return (free_stack(&a), 0);
	size = stack_size(a);
	if (size <= 5)
		sort_small(&a, &b);
	else
		radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
