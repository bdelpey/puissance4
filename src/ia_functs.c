/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_functs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelpey <bdelpey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 14:45:53 by bdelpey           #+#    #+#             */
/*   Updated: 2014/09/24 15:53:06 by bdelpey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "puissance4.h"
#include <time.h>
#include <stdio.h>

int					check_block(char **map, char player, int col)
{
	int				nb;
	int				ln;

	nb = 0;
	while (nb < col)
	{
		ln = insert_piece(map, player, nb, 0);
		if (ln != -1 && is_winner(map, player, nb, ln))
			return (nb);
		nb++;
	}
	return (-1);
}

int			rand_col(void)
{
	if (rand() % 2)
		return (2);
	else
		return (4);
}

int			chose_col(char **map, char ia)
{
	int		line[2];

	line[0] = check_col_not_full(map, 4);
	line[1] = check_col_not_full(map, 2);
	if (line[0] == 5 && line[1] == 5)
		return (rand_col());
	else if (line[0] > 0 && line[0] < 5 && line[1] > 0 && line[1] < 5)
	{
		if ((map[line[1] + 1][2] == ia && map[line[0] + 1][4] == ia)
		 || (map[line[1] + 1][2] != ia && map[line[0] + 1][4] != ia))
			return (rand_col());
		if (map[line[1] + 1][2] == ia)
			return (2);
		else
			return (4);
	}
	else if (line[0] == 5 && map[2][1] == '_')
		return (2);
	else if (line[1] == 5 && map[2][1] == '_')
		return (4);
	return (0);
}

int					default_place(char **map, char ia, int col)
{
	int				res;

	if (map[0][col / 2] == '_')
		return (col / 2);
	if ((res = chose_col(map, ia)))
		return (res);
	if (map[1][col / 2 + 1] == '_')
		return (col / 2 + 1);
	if (map[1][col / 2 - 1] == '_')
		return (col / 2 - 1);
	return (col / 2 - 2);
}
