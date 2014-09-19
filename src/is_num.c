/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 07:56:15 by vbell             #+#    #+#             */
/*   Updated: 2014/03/08 09:39:44 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int			is_num(char *str)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	if (ft_strlen(str) == 0)
		return (0);
	while (str[++i] != '\0')
	{
		if (*str != '-' && i == 0)
		{
			if (!ft_isdigit(*str))
				return (0);
		}
		else if (!ft_isdigit(str[i]) && i > 0)
			return (0);
	}
	return (1);
}
