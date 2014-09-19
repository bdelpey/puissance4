/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:40:32 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 09:34:32 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && del != NULL)
		while (*alst != NULL)
			ft_lstdelone(alst, del);
}
