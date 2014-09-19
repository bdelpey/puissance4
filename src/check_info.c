/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 08:52:31 by vbell             #+#    #+#             */
/*   Updated: 2014/03/09 15:17:44 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"puissance4.h"

int			check_col_not_full(char **map, int col)
{
	int		max;

	max = 0;
	while (map[max][col] == EMPTY_CAR)
	{
		max++;
		if (!map[max])
			break ;
	}
	max--;
	if (max == -1)
		return (-1);
	return (max);
}

int			check_player_entry(char **map, char *str)
{
	static int	max_col = 0;
	int			nb;

	if (max_col == 0)
		max_col = ft_strlen(map[0]);
	if (is_num(str))
	{
		nb = ft_atoi(str);
		if (nb > -1 && nb <= max_col)
			return (nb);
	}
	return (-1);
}
