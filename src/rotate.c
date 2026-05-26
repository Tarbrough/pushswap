/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:40:00 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/26 14:03:29 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*top;
	t_stack	*bottom;

	if (!a || !*a || !(*a)->next)
		return ;
	top = *a;
	bottom = stack_bottom(*a);
	*a = top->next;
	(*a)->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*top;
	t_stack	*bottom;

	if (!b || !*b || !(*b)->next)
		return ;
	top = *b;
	bottom = stack_bottom(*b);
	*b = top->next;
	(*b)->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rs(a);
	rs(b);
	write(1, "rr\n", 3);
}

void	rs(t_stack **s)
{
	t_stack	*top;
	t_stack	*bottom;

	if (!s || !*s || !(*s)->next)
		return ;
	top = *s;
	bottom = stack_bottom(*s);
	*s = top->next;
	(*s)->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
}
