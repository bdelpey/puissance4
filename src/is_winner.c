/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_winner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:53:10 by vbell             #+#    #+#             */
/*   Updated: 2014/03/09 14:08:17 by bdelpey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"libft.h"
#include		"puissance4.h"

int				check_vert(char **map, char player, int col, int line)
{
	static int	max = 0;
	int			nb_piece;
	int			tmp_line;

	if (max == 0)
		max = ft_len_str_tab(map);
	nb_piece = 1;
	tmp_line = line;
	while (++tmp_line < max)
	{
		if (map[tmp_line][col] == player)
			nb_piece++;
		else
			break ;
	}
	return (nb_piece);
}

static int		check_horiz_inv(char *map, int col, char player, int max)
{
	int			tmp_col;
	int			nb_piece;

	tmp_col = col;
	nb_piece = 0;
	while (++tmp_col < max)
	{
		if (map[tmp_col] == player)
			nb_piece++;
		else
			break ;
	}
	return (nb_piece);
}

int				check_horiz(char **map, char player, int col, int line)
{
	static int	max = 0;
	int			nb_piece;
	int			tmp_col;

	if (max == 0)
		max = ft_strlen(map[0]);
	nb_piece = 1;
	tmp_col = col;
	while (--tmp_col >= 0)
	{
		if (map[line][tmp_col] == player)
			nb_piece++;
		else
			break ;
	}
	nb_piece += check_horiz_inv(map[line], col, player, max);
	return (nb_piece);
}

int				is_winner(char **map, char player, int col, int line)
{
	if (check_vert(map, player, col, line) >= 4)
		return (1);
	if (check_diagleft(map, player, col, line) >= 4)
		return (1);
	if (check_diagright(map, player, col, line) >= 4)
		return (1);
	if (check_horiz(map, player, col, line) >= 4)
		return (1);
	return (0);
}
