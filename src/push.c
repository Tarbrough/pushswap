/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:40:00 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/23 11:40:00 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = stack_pop_top(b);
	if (!node)
		return ;
	stack_push_top(a, node);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = stack_pop_top(a);
	if (!node)
		return ;
	stack_push_top(b, node);
	write(1, "pb\n", 3);
}
