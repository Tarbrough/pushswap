/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 10:31:52 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/23 10:31:52 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *stack_new(int value)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node)
        return NULL;
    node->value = value;
    node->index = -1; 
    node->next = NULL;
    node->prev = NULL;
    return node;
}
int stack_size(t_stack *stack)
{
    int count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

void stack_free(t_stack **stack)
{
    t_stack *current = *stack;
    while (current)
    {
        t_stack *next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}

t_stack *stack_bottom(t_stack *stack)
{
    if (!stack)
        return NULL;
    while (stack->next)
        stack = stack->next;
    return stack;
}

void stack_move_top(t_stack **stack, t_stack *new)
{
    if (!new)
        return;
    new->next = *stack;
    new->prev = NULL;
    if (*stack)
        (*stack)->prev = new;
    *stack = new;
}

void stack_move_bottom(t_stack **stack, t_stack *new)
{
    if (!new)
        return;
    if (!*stack)
    {
        *stack = new;
        return;
    }
    t_stack *bottom = stack_bottom(*stack);
    bottom->next = new;
    new->prev = bottom;
    new->next = NULL;
}

t_stack *stack_remove_top(t_stack **stack)
{
    if (!*stack)
        return NULL;
    t_stack *top = *stack;
    *stack = top->next;
    if (*stack)
        (*stack)->prev = NULL;
    top->next = NULL;
    return top;
}

