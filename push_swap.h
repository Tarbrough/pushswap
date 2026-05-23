/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 09:50:43 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/23 09:50:43 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/* Doubly-linked stack node (top <-> bottom) */
typedef struct s_stack
{
    int             value;      /* original number */
    int             index;      /* compressed rank */
    struct s_stack  *next;      /* toward bottom */
    struct s_stack  *prev;      /* toward top */
}   t_stack;

/* parsing / errors */
int     parse_args(t_stack **a, int ac, char **av);      /* read argv into stack A */
void    print_error(void);                               /* print "Error" to stderr */

/* stack utils */
t_stack *stack_new(int value);                          /* allocate new node */
t_stack *stack_bottom(t_stack *stack);                  /* return bottom node */
void    stack_push_top(t_stack **stack, t_stack *new);   /* push node to top */
void    stack_push_bottom(t_stack **stack, t_stack *new);/* push node to bottom */
t_stack *stack_pop_top(t_stack **stack);                /* pop and return top node */
int     stack_size(t_stack *stack);                     /* count nodes in stack */
void    free_stack(t_stack **stack);                     /* free entire stack */

/* swap operations */
void    sa(t_stack **a);                                 /* swap top two of A */
void    sb(t_stack **b);                                 /* swap top two of B */
void    ss(t_stack **a, t_stack **b);                    /* swap both A and B */

/* push operations */
void    pa(t_stack **a, t_stack **b);                    /* push top of B to A */
void    pb(t_stack **a, t_stack **b);                    /* push top of A to B */

/* rotate operations */
void    ra(t_stack **a);                                 /* rotate A (top→bottom) */
void    rb(t_stack **b);                                 /* rotate B (top→bottom) */
void    rr(t_stack **a, t_stack **b);                    /* rotate both A and B */

/* reverse rotate operations */
void    rra(t_stack **a);                                /* reverse rotate A */
void    rrb(t_stack **b);                                /* reverse rotate B */
void    rrr(t_stack **a, t_stack **b);                   /* reverse rotate both */

/* indexing + sorting */
void    assign_indexes(t_stack *a);                      /* assign sorted ranks */
void    radix_sort(t_stack **a, t_stack **b);            /* binary radix algorithm */

#endif