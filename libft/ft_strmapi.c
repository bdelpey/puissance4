/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:43:46 by vbell             #+#    #+#             */
/*   Updated: 2014/01/18 09:55:06 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

size_t		ft_strlen(char const *s);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*smap;

	if (s != NULL && f != NULL)
	{
		smap = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		i = 0;
		while (s[i] != '\0')
		{
			smap[i] = f(i, s[i]);
			i++;
		}
		smap[i] = '\0';
		return (smap);
	}
	return (NULL);
}
