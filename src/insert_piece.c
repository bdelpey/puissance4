/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 09:52:25 by vbell             #+#    #+#             */
/*   Updated: 2014/03/09 11:17:22 by bdelpey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"puissance4.h"

int			insert_piece(char **map, char player, int col, int fl)
{
	int		line_pos;

	line_pos = 0;
	if ((line_pos = check_col_not_full(map, col)) != -1)
	{
		if (fl)
			map[line_pos][col] = player;
		return (line_pos);
	}
	return (-1);
}
