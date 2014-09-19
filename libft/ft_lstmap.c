/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:19:42 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 09:36:54 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<stdlib.h>
#include			"libft.h"

static void			ft_list_push_back(t_list **begin_list, t_list *data)
{
	t_list			*tmp;

	tmp = *begin_list;
	if (tmp == NULL)
		*begin_list = ft_lstnew(data->content, data->content_size);
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_lstnew(data->content, data->content_size);
	}
}

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*list;

	list = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		ft_list_push_back(&list, f(lst));
		lst = lst->next;
	}
	return (list);
}
