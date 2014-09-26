/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelpey <bdelpey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/23 09:58:52 by bdelpey           #+#    #+#             */
/*   Updated: 2014/09/26 09:56:51 by bdelpey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "puissance4.h"

int				block_vertical_fork(char **map, char c, int i, int line, t_cnct *cc)
{
	int			col;
	int			ln;

	col = 0;
	while (col < 7)
	{
		ln = insert_piece(map, c, col, 1);
		if (ln != -1)
		{
			if ((line < 5 && line > 0 && (is_winner(map, c, i, line + 1)
								|| is_winner(map, c, i, line - 1))) || 
						(line == 5 && is_winner(map, c, i, line - 1)) ||
						(line == 0 && is_winner(map, c, i, line + 1)))
			{
				map[ln][col] = EMPTY_CAR;
				ln = insert_piece(map, cc->ia, col, 1);
				if (ln == 0 || !is_winner(map, cc->player, col, ln - 1))
				{
					map[ln][col] = EMPTY_CAR;
					return (col);
				}
			}
			map[ln][col] = EMPTY_CAR;
		}
		col++;
	}
	return (-1);
}

int				vertical_fork_core(char **map, t_cnct *cc, char c)
{
	int			line;
	int			col;
	int			res;

	line = 0;
	res = -1;
	while (map[line])
	{
		col = 0;
		while (map[line][col])
		{
			if (map[line][col] == '_' && is_winner(map, c, col, line))
			{
				if ((res = block_vertical_fork(map, c, col, line, cc)) > -1)
					break;
			}
			col++;
		}
		line++;
	}
	return (res);
}

int				vertical_fork(char **map, t_cnct *c)
{
	int			res;

	res = -1;
	if ((res = vertical_fork_core(map, c, c->player)) != -1)
		return (res);
	if ((res = vertical_fork_core(map, c, c->ia)) != -1)
		return (res);
	return (res);
}

int				check_fork(char **map, char p, int ln, int cl)
{
	int			line;
	int			col;

	line = 0;
	while (line < 5)
	{
		col = 0;
		while (col < 7)
		{
			if (map[line][col] == '_' && is_winner(map, p, col, line) &&
				map[line + 1][col] == '_' && is_winner(map, p, col, line + 1))
			{
				map[ln][cl] = '_';
				if (!(map[line][col] == '_' && is_winner(map, p, col, line) &&
					map[line + 1][col] == '_' && is_winner(map, p, col, line + 1)))
				return (1);
			}
			col++;
		}
		line++;
	}
	return (0);
}

int				one_move(char **map, t_cnct *c, char p)
{
	int			res;
	int			col;
	int			ln;

	col = 0;
	res = -1;
	while (col < 7)
	{
		ln = insert_piece(map, p, col, 1);
		if (ln != -1)
		{
			if ((res = check_fork(map, p, ln, col)))
			{
				if (ln == 0 || !is_winner(map, c->player, col, ln - 1))
					return (col);
			}
			map[ln][col] = '_';
		}
		col++;
	}
	return (-1);
}

int				one_move_vertical_fork(char **map, t_cnct *c)
{
	int			res;

	res = -1;
	if ((res = one_move(map, c, c->player)) != -1)
		return (res);
	if ((res = one_move(map, c, c->ia)) != -1)
		return (res);
	return (res);
}
