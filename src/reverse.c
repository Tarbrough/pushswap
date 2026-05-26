/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:40:00 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/26 14:03:27 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	rrs(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rrs(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrs(a);
	rrs(b);
	write(1, "rrr\n", 4);
}

void	rrs(t_stack **s)
{
	t_stack	*bottom;
	t_stack	*pre;

	if (!s || !*s || !(*s)->next)
		return ;
	bottom = stack_bottom(*s);
	pre = bottom->prev;
	pre->next = NULL;
	bottom->prev = NULL;
	bottom->next = *s;
	(*s)->prev = bottom;
	*s = bottom;
}
