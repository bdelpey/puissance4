/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:27:42 by vbell             #+#    #+#             */
/*   Updated: 2014/02/15 21:30:22 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<string.h>

size_t			ft_strlen(char const *str);

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*strsub;
	size_t		i;

	i = 0;
	if (s != NULL)
	{
		strsub = (char *)malloc(sizeof(char) * len + 1);
		if ((start + len) > ft_strlen(s))
			return (NULL);
		while (i < len)
		{
			strsub[i] = s[start + i];
			i++;
		}
		strsub[i] = '\0';
		return (strsub);
	}
	return (NULL);
}
