/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:31:58 by vbell             #+#    #+#             */
/*   Updated: 2013/12/11 15:42:42 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<string.h>

size_t			ft_strlen(char const *s1);

static int		ft_strncmp2(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && n - 1 > 0)
	{
		if (*s2 == '\0')
			break ;
		n--;
		s1++;
		s2++;
		if (*s1 == '\0')
			break ;
	}
	if (*s2 == '\0')
		return (0);
	if (*s1 > *s2)
		return (1);
	if (*s1 == *s2 && n == 1)
		return (0);
	else
		return (-1);
}

char			*ft_strnstr(const char *str, const char *mini, size_t len)
{
	char	*find;

	find = NULL;
	if (*mini == '\0')
		return ((char *)str);
	if (len == 0 || len < ft_strlen(mini))
		return (NULL);
	while (*str != '\0')
	{
		if (*str == *mini)
			if (ft_strncmp2(&(*str), mini, len) == 0)
			{
				find = (char *)str;
				return (find);
			}
			str++;
	}
	return (find);
}
