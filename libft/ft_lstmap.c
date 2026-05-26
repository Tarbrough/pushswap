/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                       :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: jbauch <jbauch@student.42wolfsburg.de>      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:26:00 by jbauch             #+#    #+#            */
/*   Updated: 2025/12/15 02:26:00 by jbauch            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_object;
	void	*func;

	if (!list || !f || !del)
		return (NULL);
	new_list = NULL;
	while (list)
	{
		func = f(list->content);
		new_object = ft_lstnew(func);
		if (!new_object)
		{
			ft_lstclear(&new_list, del);
			free(func);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_object);
		list = list->next;
	}
	return (new_list);
}
