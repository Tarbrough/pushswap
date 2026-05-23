/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:40:00 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/23 11:40:00 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*bottom;

	if (stack_size(*a) < 2)
		return ;
	bottom = stack_bottom(*a);
	if (bottom->prev)
		bottom->prev->next = NULL;
	bottom->prev = NULL;
	bottom->next = *a;
	(*a)->prev = bottom;
	*a = bottom;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rra(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
