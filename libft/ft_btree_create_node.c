/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 09:58:56 by vbell             #+#    #+#             */
/*   Updated: 2014/01/18 10:00:34 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_btree		*btree_create_node(void *item)
{
	t_btree		*btree;

	btree = (t_btree *)malloc(sizeof(t_btree));
	btree->left = NULL;
	btree->right = NULL;
	btree->item = item;
	return (btree);
}
