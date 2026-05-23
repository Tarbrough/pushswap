/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:13:10 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/23 11:13:10 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void radix_sort(t_stack **a, t_stack **b)
{
    int max_index = stack_size(*a) - 1;
    int max_bits = 0;
    while ((max_index >> max_bits) != 0)
        max_bits++;

    for (int i = 0; i < max_bits; i++)
    {
        int size = stack_size(*a);
        for (int j = 0; j < size; j++)
        {
            if (((*a)->index >> i) & 1)
                ra(a);
            else
                pb(a, b);
        }
        while (*b)
            pa(a, b);
    }
}