/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:01:31 by vbell             #+#    #+#             */
/*   Updated: 2014/02/15 21:28:39 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<string.h>

void			*ft_memchr(const void *s, int c, size_t n)
{
	char		*tmp;
	size_t		i;

	i = 0;
	tmp = (char *)s;
	while (i < n)
	{
		if (tmp[i] == c)
			return (&tmp[i]);
		i++;
	}
	return (NULL);
}
