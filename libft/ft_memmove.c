/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:29:00 by jbauch             #+#    #+#            */
/*   Updated: 2025/12/15 02:29:00 by jbauch            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;
	int					i;

	cdest = (unsigned char *)dest;
	csrc = (const unsigned char *)src;
	if (n == 0 || dest == src)
		return (dest);
	i = (int)(n - 1);
	if (dest > src)
	{
		while (i >= 0)
		{
			cdest[i] = csrc[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
