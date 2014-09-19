/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 08:46:01 by vbell             #+#    #+#             */
/*   Updated: 2013/12/23 09:35:25 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>

char		*ft_strchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			tmp = (char *)&s[i];
			return (tmp);
		}
		i++;
	}
	if (s[i] == c)
	{
		tmp = (char *)&s[i];
		return (tmp);
	}
	return (NULL);
}
