/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:31:56 by vbell             #+#    #+#             */
/*   Updated: 2014/01/18 09:57:02 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int			ft_strcmp(const char *s1, const char *s2);

void		ft_sort_str_tab(char **tab)
{
	int		x;
	int		y;
	char	*tmp;

	x = 0;
	if (tab != NULL)
		while (tab[x] != NULL)
		{
			y = x + 1;
			while (tab[y] != NULL)
			{
				if (ft_strcmp(tab[x], tab[y]) > 0)
				{
					tmp = tab[x];
					tab[x] = tab[y];
					tab[y] = tmp;
				}
				y++;
			}
			x++;
		}
}
