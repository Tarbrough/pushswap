/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:29:00 by jbauch             #+#    #+#            */
/*   Updated: 2025/12/15 02:29:00 by jbauch            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*new;

	len = ft_strlen(src);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_memcpy(new, src, len + 1);
	return (new);
}
