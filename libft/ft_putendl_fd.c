/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:11:17 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 09:49:13 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void		ft_putstr_fd(char const *s, int fd);
void		ft_putchar_fd(char c, int fd);

void		ft_putendl_fd(char const *s, int fd)
{
	if (s != NULL)
		ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
