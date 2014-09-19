/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:09:52 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 09:48:51 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

void		ft_putstr(char const *s);
void		ft_putchar(char c);

void		ft_putendl(char const *s)
{
	if (s != NULL)
		ft_putstr(s);
	ft_putchar('\n');
}
