/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:55:43 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 09:35:14 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"libft.h"

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*tmp;

	if (lst != NULL && f != NULL)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			f(tmp);
			tmp = tmp->next;
		}
	}
}
