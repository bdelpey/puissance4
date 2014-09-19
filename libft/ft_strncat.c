/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:10:53 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 10:04:05 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (*src != '\0' && n > 0)
	{
		dest[i] = *src;
		i++;
		src++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}
