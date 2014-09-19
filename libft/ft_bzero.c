/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:38:03 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 09:29:08 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<string.h>

void			ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*tmp;

	tmp = s;
	i = 0;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
}