/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 13:35:27 by vbell             #+#    #+#             */
/*   Updated: 2014/03/08 19:22:22 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"puissance4.h"

void		init_max_len(int *nb_piece, int *max_ln, int *max_col, char **map)
{
	static int	ln = 0;
	static int	col = 0;

	if (ln == 0 && col == 0)
	{
		col = ft_strlen(map[0]);
		ln = ft_len_str_tab(map);
	}
	*max_col = col;
	*max_ln = ln;
	*nb_piece = 1;
}

static int	check_diagleft_inv(char **map, char player, int col, int line)
{
	int		max_ln;
	int		max_col;
	int		nb_piece;
	int		tmp_col;
	int		tmp_line;

	init_max_len(&nb_piece, &max_ln, &max_col, map);
	nb_piece = 0;
	tmp_col = col;
	tmp_line = line;
	while (++tmp_col < max_col && ++tmp_line < max_ln)
	{
		if (map[tmp_line][tmp_col] == player)
			nb_piece++;
		else
			break ;
	}
	return (nb_piece);
}

static int	check_diagright_inv(char **map, char player, int col, int line)
{
	int		max_ln;
	int		max_col;
	int		nb_piece;
	int		tmp_col;
	int		tmp_line;

	init_max_len(&nb_piece, &max_ln, &max_col, map);
	nb_piece = 0;
	tmp_col = col;
	tmp_line = line;
	while (--tmp_col >= 0 && ++tmp_line < max_ln)
	{
		if (map[tmp_line][tmp_col] == player)
			nb_piece++;
		else
			break ;
	}
	return (nb_piece);
}

int			check_diagleft(char **map, char player, int col, int line)
{
	int		max_ln;
	int		max_col;
	int		nb_piece;
	int		tmp_col;
	int		tmp_line;

	init_max_len(&nb_piece, &max_ln, &max_col, map);
	tmp_col = col;
	tmp_line = line;
	while (--tmp_col >= 0 && --tmp_line >= 0)
	{
		if (map[tmp_line][tmp_col] == player)
			nb_piece++;
		else
			break ;
	}
	nb_piece += check_diagleft_inv(map, player, col, line);
	return (nb_piece);
}

int			check_diagright(char **map, char player, int col, int line)
{
	int		max_ln;
	int		max_col;
	int		nb_piece;
	int		tmp_col;
	int		tmp_line;

	init_max_len(&nb_piece, &max_ln, &max_col, map);
	tmp_col = col;
	tmp_line = line;
	while (++tmp_col < max_col && --tmp_line >= 0)
	{
		if (map[tmp_line][tmp_col] == player)
			nb_piece++;
		else
			break ;
	}
	nb_piece += check_diagright_inv(map, player, col, line);
	return (nb_piece);
}
