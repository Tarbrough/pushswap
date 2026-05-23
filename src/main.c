/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 09:50:11 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/23 09:50:11 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int ac, char **av)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (ac < 2)
        return 0;

    if (!parse_args(&a, ac, av) || has_duplicates(a))
    {
        print_error();
        stack_free(&a);
        return 1;
    }

    assign_indexes(a);

    int size = stack_size(a);
    if (size <= 5)
        small_sort(&a, &b);
    else
        radix_sort(&a, &b);

    stack_free(&a);
    stack_free(&b);
    return 0;
}