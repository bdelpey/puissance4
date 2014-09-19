/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:51:39 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 09:34:01 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	if (new != NULL)
	{
		if (*alst == NULL)
			*alst = ft_lstnew(new->content, new->content_size);
		else if (alst != NULL && (*alst != new) && new != NULL)
		{
			new->next = *alst;
			*alst = new;
		}
	}
}
