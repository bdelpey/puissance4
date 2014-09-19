/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:46:10 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 09:40:55 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<string.h>

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*nsrc;
	char		*ndest;

	ndest = (char *)dest;
	nsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (ndest);
}
