/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:38:22 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 09:39:42 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<string.h>

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*nsrc;
	char		*ndest;

	ndest = (char *)dest;
	nsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		if (nsrc[i] == c)
		{
			ndest[i] = c;
			ndest = ndest + i + 1;
			return (ndest);
		}
		if (i < n)
			ndest[i] = nsrc[i];
		i++;
	}
	return (NULL);
}
