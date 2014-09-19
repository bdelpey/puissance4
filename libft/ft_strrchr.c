/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 08:57:12 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 10:07:47 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

size_t		ft_strlen(const char *s);

char		*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		i;
	int		ln;

	ln = ft_strlen(s);
	tmp = (char *)s;
	i = ln;
	while (i >= 0)
	{
		if (tmp[i] == c)
			return (&tmp[i]);
		i--;
	}
	return (NULL);
}
