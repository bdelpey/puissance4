/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:43:34 by vbell             #+#    #+#             */
/*   Updated: 2014/01/18 09:58:14 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>

void			*ft_memalloc(size_t size)
{
	void		*mem;
	char		*tmp;
	size_t		i;

	i = 0;
	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	tmp = (char *)mem;
	tmp[0] = 0;
	while (i < size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
