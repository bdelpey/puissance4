/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:42:48 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 10:09:47 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<string.h>

static int		ft_cmp(const char *str, const char *str2)
{
	while (*str == *str2 && *str2 != '\0')
	{
		str++;
		str2++;
	}
	if (*str2 == '\0')
		return (1);
	return (0);
}

char			*ft_strstr(const char *str, const char *mini)
{
	char	*find;

	find = NULL;
	if (*mini == '\0')
		return ((char *)str);
	while (*str != '\0')
	{
		if (*str == *mini)
			if (ft_cmp(&(*str), mini))
			{
				find = (char *)str;
				return (find);
			}
		str++;
	}
	return (find);
}
