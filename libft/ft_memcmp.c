/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:18:13 by vbell             #+#    #+#             */
/*   Updated: 2014/01/18 09:57:51 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<string.h>

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char		*ns1;
	char		*ns2;
	size_t		i;

	i = 0;
	ns1 = (char *)s1;
	ns2 = (char *)s2;
	if (ns1 == NULL && ns2 == NULL)
		return (0);
	while (ns1[i] == ns2[i] && i < n)
		i++;
	if (i != n)
		return (ns1[i] - ns2[i]);
	else
		return (ns1[i - 1] - ns2[i - 1]);
}
