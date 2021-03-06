/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:00:02 by vbell             #+#    #+#             */
/*   Updated: 2013/12/05 07:28:28 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (*src != '\0')
	{
		dest[i++] = *src;
		++src;
	}
	dest[i] = '\0';
	return (dest);
}
