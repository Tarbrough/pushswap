/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:29:00 by jbauch             #+#    #+#            */
/*   Updated: 2025/12/15 02:29:00 by jbauch            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int				word_count(char const *str, char delimiter);
static void		ft_free(char **str);
char			*append_word(char const*str, int start, int end);
static void		variable_set(int *i, int *start, int *j);

char	**ft_split(char const *s, char c)
{
	char		**word;
	int			i;
	int			start;
	int			j;

	variable_set(&i, &start, &j);
	word = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!word)
		return (NULL);
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && start >= 0)
		{
			word[j] = append_word(s, start, i);
			if (!(word[j]))
				return (ft_free(word), NULL);
			start = -1;
			j++;
		}
		i++;
	}
	return (word);
}

int	word_count(char const *str, char delimiter)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*str != '\0')
	{
		if (*str != delimiter && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*str == delimiter)
		{
			i = 0;
		}
		str++;
	}
	return (count);
}

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*append_word(char const*str, int start, int end)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc(((end - start) + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static void	variable_set(int *i, int *start, int *j)
{
	*i = 0;
	*j = 0;
	*start = -1;
}
