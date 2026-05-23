/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                         :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:26:00 by jbauch             #+#    #+#            */
/*   Updated: 2025/12/15 02:26:00 by jbauch            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_forbidden(int i)
{
	if (i >= 9 && i <= 13)
		return (1);
	if (i == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *src)
{
	int	output;
	int	i;
	int	sign;

	output = 0;
	sign = 1;
	i = 0;
	while (ft_char_forbidden(src[i]))
		i++;
	if (src[i] == '+' && src[i + 1] != '-')
		i++;
	if (src[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (src[i] && src[i] >= '0' && src[i] <= '9')
	{
		output *= 10;
		output += src[i] - '0';
		i++;
	}
	return (output * sign);
}
