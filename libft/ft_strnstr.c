/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:29:00 by jbauch             #+#    #+#            */
/*   Updated: 2025/12/15 02:29:00 by jbauch            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *src, const char *query, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (query[0] == 0)
		return ((char *)src);
	while (src[i] && i < n)
	{
		while (src[i + j] == query[j] && src[i + j] && i + j < n)
		{
			j++;
			if (query[j] == 0)
				return ((char *)src + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
