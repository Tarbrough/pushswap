/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 09:50:43 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/26 14:04:55 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* parsing / errors */
int		parse_args(t_stack **a, int ac, char **av);
void	print_error(void);

/* stack utils */
t_stack	*stack_new(int value);
t_stack	*stack_bottom(t_stack *stack);
void	stack_push_top(t_stack **stack, t_stack *new);
void	stack_push_bottom(t_stack **stack, t_stack *new);
t_stack	*stack_pop_top(t_stack **stack);
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);

/* swap operations */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	swap_s(t_stack **s);

/* push operations */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/* rotate operations */
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rs(t_stack **s);

/* reverse rotate operations */
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rrs(t_stack **s);

/* indexing + sorting */
void	assign_indexes(t_stack *a);
int		is_sorted(t_stack *a);
int		position_of_index(t_stack *a, int index);
void	bring_to_top(t_stack **a, int index);
void	sort_small(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b);
void	free_split(char **s);
int		has_duplicate(t_stack *a, int value);
int		ps_atoi(const char *s, int *out);
int		is_number(const char *s);

#endif
