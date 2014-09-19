/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 09:58:42 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 09:35:39 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	if (alst != NULL && del != NULL)
	{
		tmp = *alst;
		del(tmp->content, tmp->content_size);
		*alst = (*alst)->next;
		free(tmp);
		tmp = NULL;
	}
}
