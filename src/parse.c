/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolsfburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:03:58 by jbauch            #+#    #+#             */
/*   Updated: 2026/05/26 14:03:26 by jbauch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	parse_token(t_stack **a, char *token)
{
	int		value;
	t_stack	*node;

	if (!is_number(token) || !ps_atoi(token, &value) || has_duplicate(*a,
			value))
		return (0);
	node = stack_new(value);
	if (!node)
		return (0);
	stack_push_bottom(a, node);
	return (1);
}

int	parse_args(t_stack **a, int ac, char **av)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			if (!parse_token(a, split[j]))
			{
				free_split(split);
				return (0);
			}
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}
