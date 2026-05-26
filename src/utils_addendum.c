/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_addendum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:41:20 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/26 14:03:31 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_addendum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:40:00 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/23 12:40:00 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push_top(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

void	stack_push_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*bottom;

	if (!new)
		return ;
	if (!*stack)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return ;
	}
	bottom = stack_bottom(*stack);
	bottom->next = new;
	new->prev = bottom;
	new->next = NULL;
}

t_stack	*stack_pop_top(t_stack **stack)
{
	t_stack	*top;

	if (!*stack)
		return (NULL);
	top = *stack;
	*stack = top->next;
	if (*stack)
		(*stack)->prev = NULL;
	top->next = NULL;
	top->prev = NULL;
	return (top);
}

int	position_of_index(t_stack *a, int index)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index == index)
			return (pos);
		a = a->next;
		pos++;
	}
	return (-1);
}

void	bring_to_top(t_stack **a, int index)
{
	int	pos;
	int	size;

	pos = position_of_index(*a, index);
	size = stack_size(*a);
	if (pos <= size / 2)
		while ((*a)->index != index)
			ra(a);
	else
		while ((*a)->index != index)
			rra(a);
}
