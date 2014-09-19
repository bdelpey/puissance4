/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:55:47 by vbell             #+#    #+#             */
/*   Updated: 2013/12/15 20:16:37 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<string.h>

size_t			ft_strlen(const char *s);

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*ndest;
	char		*nsrc;
	size_t		len;
	size_t		i;

	i = 0;
	ndest = dest;
	nsrc = (char *)src;
	len = ft_strlen(dest);
	if (size < ft_strlen(dest))
		len = size;
	if (ft_strlen(dest) >= size)
		return (size + ft_strlen(nsrc));
	while (nsrc[i] != '\0')
	{
		if (i < size - len - 1)
			ndest[i + len] = nsrc[i];
		i++;
	}
	ndest[size - 1] = '\0';
	return (len + ft_strlen(src));
}
