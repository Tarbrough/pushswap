/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:40:00 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/23 11:40:00 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*top;
	t_stack	*bottom;

	if (stack_size(*a) < 2)
		return ;
	top = stack_pop_top(a);
	bottom = stack_bottom(*a);
	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	ra(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
