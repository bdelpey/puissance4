/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:36:12 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 10:06:43 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<string.h>

char			*ft_strnew(size_t size)
{
	char		*new_tab;
	size_t		i;

	i = 0;
	new_tab = (char *)malloc(sizeof(char) * size);
	if (size == 0)
	{
		new_tab[0] = '\0';
		return (new_tab);
	}
	if (new_tab == NULL)
		return (NULL);
	while (i < size)
	{
		new_tab[i] = '\0';
		i++;
	}
	return (new_tab);
}
