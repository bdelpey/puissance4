/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 13:01:04 by vbell             #+#    #+#             */
/*   Updated: 2014/03/09 17:44:00 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"libft.h"

void		*ft_realloc(void *line, int size)
{
	void	*new;

	new = malloc(size);
	if (new == NULL)
		return (NULL);
	if (line != NULL)
		ft_memcpy(new, line, size);
	ft_memdel(&line);
	return (new);
}
