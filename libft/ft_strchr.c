/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:29:00 by jbauch             #+#    #+#            */
/*   Updated: 2025/12/15 02:29:00 by jbauch            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	unsigned int	i;
	char			ch;

	ch = (char)c;
	i = 0;
	while (src[i])
	{
		if (src[i] == ch)
			return ((char *) &src[i]);
		i++;
	}
	if (src[i] == ch)
		return ((char *) &src[i]);
	return (NULL);
}
