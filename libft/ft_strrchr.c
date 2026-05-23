/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:29:00 by jbauch             #+#    #+#            */
/*   Updated: 2025/12/15 02:29:00 by jbauch            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	const char		*out;
	unsigned char	ch;

	ch = (unsigned char)c;
	out = '\0';
	while (*src)
	{
		if ((unsigned char)*src == ch)
			out = src;
		src++;
	}
	if (ch == '\0')
		return ((char *)src);
	return ((char *)out);
}
