/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:51:44 by vbell             #+#    #+#             */
/*   Updated: 2014/03/09 08:37:03 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>

size_t			ft_strlen(char const *s);

static int		ft_nbwhite(char *s, int sect, int i)
{
	int			nb;

	nb = 0;
	if (sect == 0)
	{
		while (*s == '\n' || *s == ' ' || *s == '\t'
				|| *s == '\v' || *s == '\r' || *s == '\f')
		{
			nb++;
			s++;
		}
		return (nb);
	}
	else
	{
		while (s[i - 1] == '\n' || s[i - 1] == ' ' || s[i - 1] == '\t'
				|| s[i - 1] == '\v' || s[i - 1] == '\r' || s[i - 1] == '\f')
		{
			nb++;
			i--;
		}
		return (nb);
	}
}

char			*ft_strtrim(char *s)
{
	int			len;
	char		*str;
	int			nb_white[2];
	int			count[2];

	count[0] = 0;
	count[1] = -1;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	nb_white[0] = ft_nbwhite(s, 0, len);
	nb_white[1] = len - ft_nbwhite(s, 1, len);
	if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (s[++count[1]] != '\0')
		if (count[1] >= nb_white[0] && count[1] < nb_white[1])
		{
			str[count[0]] = s[count[1]];
			count[0]++;
		}
	str[count[0]] = '\0';
	return (str);
}
