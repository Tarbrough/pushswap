/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:13:10 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/23 12:01:34 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	radix_pass(t_stack **a, t_stack **b, int bit)
{
	int	size;
	int	j;

	size = stack_size(*a);
	j = 0;
	while (j < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		j++;
	}
	while (*b)
		pa(a, b);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_index;
	int	max_bits;
	int	i;

	assign_indexes(*a);
	max_index = stack_size(*a) - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		radix_pass(a, b, i);
		i++;
	}
}
