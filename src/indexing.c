/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 10:53:57 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/26 14:03:24 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_min_unindexed(t_stack *a)
{
	t_stack	*min;

	min = NULL;
	while (a)
	{
		if (a->index == -1 && (!min || a->value < min->value))
			min = a;
		a = a->next;
	}
	return (min);
}

void	assign_indexes(t_stack *a)
{
	int		i;
	t_stack	*min;

	i = 0;
	while (1)
	{
		min = find_min_unindexed(a);
		if (!min)
			break ;
		min->index = i++;
	}
}
