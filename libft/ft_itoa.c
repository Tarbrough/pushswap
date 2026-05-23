/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:29:00 by jbauch             #+#    #+#            */
/*   Updated: 2025/12/15 02:29:00 by jbauch            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	check_length(long nbr);
static char	*mem(int len);

char	*ft_itoa(int n)
{
	int				len;
	int				i;
	static long		nbr;
	char			*output;

	nbr = n;
	len = check_length(nbr);
	output = mem(len);
	i = len - 1;
	if (!output)
		return (NULL);
	if (nbr < 0)
		nbr *= -1;
	while (nbr != 0)
	{
		output[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		output[0] = '-';
	output[len] = 0;
	return (output);
}

static int	check_length(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	else if (nbr == 0)
	{
		count ++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static char	*mem(int len)
{
	char	*temp;

	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
	{
		return (NULL);
	}
	temp[0] = '0';
	return (temp);
}
