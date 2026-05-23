/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:29:00 by jbauch             #+#    #+#            */
/*   Updated: 2025/12/15 02:29:00 by jbauch            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(const char *string, char (*function)(unsigned int, char))
{
	int		i;
	char	*result;

	i = 0;
	result = malloc((ft_strlen(string) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < ft_strlen(string))
	{
		result[i] = (*function)(i, string[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
