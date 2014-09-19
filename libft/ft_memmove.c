/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:56:19 by vbell             #+#    #+#             */
/*   Updated: 2014/02/15 21:29:13 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>
#include	<stdlib.h>

void		*ft_memcpy(void *dest, const void *src, size_t n);

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ndest;
	char	*nsrc;
	void	*tmp;

	tmp = malloc(sizeof(src));
	ndest = (char *)dest;
	nsrc = (char *)src;
	if (ndest <= nsrc || nsrc >= (ndest + n))
		return (ft_memcpy(dest, src, n));
	else
	{
		ft_memcpy(tmp, src, n);
		ft_memcpy(dest, tmp, n);
		free(tmp);
		return (dest);
	}
}
