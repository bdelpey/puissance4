/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_advanced_fork.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelpey <bdelpey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/22 12:44:39 by bdelpey           #+#    #+#             */
/*   Updated: 2014/09/26 09:59:05 by bdelpey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "puissance4.h"

int				double_win(char **map, char c, int col)
{
	int				nb;
	int				ln;
	int 			count;

	nb = 0;
	count = 0;
	while (nb < col)
	{
		ln = insert_piece(map, c, nb, 0);
		if (ln != -1 && is_winner(map, c, nb, ln))
			count++;
		if (count == 2)
			return (1);
		nb++;
	}
	return (0);
}

int				god_fork(char **map, t_cnct *c, int col)
{
	int			frk;
	int			ln;

	if ((frk = check_block(map, c->ia, col)) != -1)
	{
		ln = insert_piece(map, c->player, frk, 1);
		if (ln > 0 && is_winner(map, c->ia, frk, ln - 1))
		{
			map[ln][frk] = EMPTY_CAR;
			return (1);
		}
		map[ln][frk] = EMPTY_CAR;
	}
	return (0);
}

int				for_ia(char **map, t_cnct *c, int col)
{
	int			nb;
	int			ln;

	nb = 0;
	while (nb < col)
	{
		ln = insert_piece(map, c->ia, nb, 1);
		if (ln != -1)
		{
			if (double_win(map, c->ia, col) || god_fork(map, c, col))
			{
				map[ln][nb] = EMPTY_CAR;
				if (ln == 0 || !is_winner(map, c->player, nb, ln - 1))
					return (nb);
			}
			map[ln][nb] = EMPTY_CAR;
		}
		nb++;
	}
	return (-1);
}

int				god_fork_pl(char **map, t_cnct *c, int col)
{
	int			frk;
	int			ln;

	if ((frk = check_block(map, c->player, col)) != -1)
	{
		ln = insert_piece(map, c->ia, frk, 1);
		if (ln > 0 && is_winner(map, c->player, frk, ln - 1))
		{
			map[ln][frk] = EMPTY_CAR;
			return (1);
		}
		map[ln][frk] = EMPTY_CAR;
	}
	return (0);
}

int				for_player(char **map, t_cnct *c, int col)
{
	int			nb;
	int			ln;

	nb = 0;
	while (nb < col)
	{
		ln = insert_piece(map, c->player, nb, 1);
		if (ln != -1)
		{
			if (double_win(map, c->player, col) || god_fork_pl(map, c, col))
			{
				map[ln][nb] = EMPTY_CAR;
				if ((ln == 0 || !is_winner(map, c->player, nb, ln - 1)))
					return (nb);
			}
			map[ln][nb] = EMPTY_CAR;
		}
		nb++;
	}
	return (-1);
}

int				check_advanced_fork(char **map, t_cnct *c, int col)
{
	int			res;

	res = -1;
	res = for_ia(map, c, col);
	if (res == -1)
		res = for_player(map, c, col);
	return (res);
}
