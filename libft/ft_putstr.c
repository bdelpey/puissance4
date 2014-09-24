/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:08:56 by vbell             #+#    #+#             */
/*   Updated: 2014/09/22 12:55:06 by bdelpey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr(char const *str)
{
	if (str != NULL)
	{
		while (*str)
		{
			write(1, " ", 1);
			if (*str == 'X')
				write(1, "\033[1;31m", 7);
			if (*str == 'O')
				write(1, "\033[1;35m", 7);
			write(1, &*(str++), 1);
			write(1, "\033[0;m", 5);
		}
	}
}
