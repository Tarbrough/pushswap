/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 10:53:57 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/23 10:53:57 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void assign_index(t_stack *a)
{
    int size = stack_size(a);
    int *values = malloc(size * sizeof(int));
    if (!values)
        return;

    t_stack *current = a;
    for (int i = 0; i < size; i++)
    {
        values[i] = current->value;
        current = current->next;
    }

    // Simple selection sort to rank values
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (values[j] < values[min_idx])
                min_idx = j;
        }
        int temp = values[i];
        values[i] = values[min_idx];
        values[min_idx] = temp;
    }

    // Assign indexes based on sorted order
    current = a;
    while (current)
    {
        for (int i = 0; i < size; i++)
        {
            if (current->value == values[i])
            {
                current->index = i;
                break;
            }
        }
        current = current->next;
    }
    free(values);
}

static int find_unindexed(t_stack *stack)
{
     long    min;
    t_stack *tmp;

    min = 2147483648;
    tmp = a;
    while (tmp)
    {
        if (tmp->index == -1 && tmp->value < min)
            min = tmp->value;
        tmp = tmp->next;
    }
    return ((int)min);
}