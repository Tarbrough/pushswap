/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:40:00 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/23 13:10:38 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_number(const char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

int	has_duplicate(t_stack *a, int value)
{
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	ft_atoi(const char *s, int *out)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		if ((n * sign) > 2147483647 || (n * sign) < -2147483648)
			return (0);
		s++;
	}
	*out = (int)(n * sign);
	return (1);
}

int	parse_args(t_stack **a, int ac, char **av)
{
	int		i;
	int		value;
	t_stack	*node;

	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]) || !ft_atoi(av[i], &value)
			|| has_duplicate(*a, value))
			return (0);
		node = stack_new(value);
		if (!node)
			return (0);
		stack_push_bottom(a, node);
		i++;
	}
	assign_indexes(*a);
	return (1);
}
