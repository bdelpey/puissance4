/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:51:21 by vbell             #+#    #+#             */
/*   Updated: 2014/03/12 18:08:15 by bdelpey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static void		print_last_line(int len)
{
	int			i;

	i = 0;
	while (i++ < len)
	{
		write(1, " ", 1);
		ft_putnbr(i % 10);
	}
	write(1, "\n", 1);
}

void			ft_print_str_tab(char **tab)
{
	int			i;
	static int	len = 0;
	static int	high = 0;

	if (!high)
		high = ft_len_str_tab(tab);
	if (!len)
		len = ft_strlen(tab[0]);
	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		write(1, "\n", 1);
		i++;
	}
	print_last_line(len);
}
