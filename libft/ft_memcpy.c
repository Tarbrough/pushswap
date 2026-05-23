/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:29:00 by jbauch             #+#    #+#            */
/*   Updated: 2025/12/15 02:29:00 by jbauch            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				count;
	size_t				size;
	unsigned char		*cdest;
	const unsigned char	*csrc;

	size = n;
	count = 0;
	cdest = dest;
	csrc = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (count < size)
	{
		cdest[count] = csrc[count];
		count++;
	}
	return (dest);
}
