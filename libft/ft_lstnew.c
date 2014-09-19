/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:16:17 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 10:18:01 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		"libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_list->content_size = 0;
		new_list->content = NULL;
	}
	else
	{
		new_list->content_size = content_size;
		new_list->content = (void *)malloc(sizeof(t_list) * content_size);
		ft_memcpy(new_list->content, content, content_size);
	}
	new_list->next = NULL;
	return (new_list);
}
