/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelpey <bdelpey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:25:30 by bdelpey           #+#    #+#             */
/*   Updated: 2015/01/01 17:55:43 by bdelpey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "puissance4.h"
#include <stdio.h>

int					check_left_places(char **map, int col)
{
	int				i;

	i = 0;
	while (i < col)
	{
		if (map[0][i] == '_')
			return (i);
		i++;
	}
	return (-1);
}

int					starters_check(char **map, t_cnct *c, int col)
{
	if ((c->NB = check_block(map, c->ia, col)) != -1)
	{
		c->LN = insert_piece(map, c->ia, c->NB, 1);
		return (1);
	}
	if ((c->NB = check_block(map, c->player, col)) != -1)
	{
		c->LN = insert_piece(map, c->ia, c->NB, 1);
		return (1);
	}
	if ((c->NB = check_advanced_fork(map, c, col)) != -1)
	{
		c->LN = insert_piece(map, c->ia, c->NB, 1);
		return (1);
	}
	if ((c->NB = vertical_fork(map, c)) != -1)
	{
		c->LN = insert_piece(map, c->ia, c->NB, 1);
		return (1);
	}
	if ((c->NB = one_move_vertical_fork(map, c)) != -1)
	{
		c->LN = insert_piece(map, c->ia, c->NB, 1);
		return (1);
	}
	return (0);
}

int					dont_be_dumb(char **map, t_cnct *c)
{
	c->LN = insert_piece(map, c->ia, c->NB, 1);
	if (c->LN != -1 && (one_move(map, c, c->player) == -1) && (vertical_fork_core(map, c, c->player) == -1) && (for_player(map, c, 7) == -1))
	{
		map[c->LN][c->NB] = '_';
		return (1);
	}
	if (c->LN != -1)
		map[c->LN][c->NB] = '_';
	return (0);
}

int					be_smart(char **map, t_cnct *c, int col, int *fl)
{
	int				fcked;

	fcked = 0;
	c->NB = default_place(map, c->ia, col);
	while (c->LN == -1 && fcked < 2 * col)
	{
		c->LN = insert_piece(map, c->ia, c->NB, 0);
		if ((c->LN != -1 && *fl == 3 && (!c->LN || (!is_winner(map, c->player, c->NB, c->LN - 1) && dont_be_dumb(map, c) && !is_winner(map, c->ia, c->NB, c->LN - 1)))) ||
			(c->LN != -1 && *fl == 2 && (!c->LN || (!is_winner(map, c->player, c->NB, c->LN - 1) && dont_be_dumb(map, c)))) ||
			(c->LN != -1 && *fl == 1 && (!c->LN || !is_winner(map, c->player, c->NB, c->LN - 1))))
		{
			insert_piece(map, c->ia, c->NB, 1);
			*fl = 0;
			break;
		}
		else if (c->NB == col - 1)
			c->NB = 0;
		else
			c->NB++;
		c->LN = -1;
		fcked++;
	}
	return (fcked);
}

static void			print_res(char player, int nb)
{
	if (player == PLAYER_B)
		write(1, "\033[1;31m", 7);
	if (player == PLAYER_A)
		write(1, "\033[1;35m", 7);
	ft_putstr_fd("-- ", 1);
	write(1, "\033[0;m", 5);
	ft_putstr_fd("Ia Played in ", 1);
	ft_putnbr_fd(nb, 1);
	ft_putendl_fd("", 1);
}

int					ia_turn(char **map, char ia, char player)
{
	static int		col = 0;
	t_cnct			c;
	int				fcked;
	int				fl;

	fl = 3;
	c.player = player;
	c.ia = ia;
	c.LN = -1;
	if (!col)
		col = ft_strlen(map[0]);
	if (starters_check(map, &c, col))
		fcked = 0;
	else
	{
		while (fl)
		{
			fcked = be_smart(map, &c, col, &fl);
			if (fl)
				--fl;
		}
	}
	if (fcked == 2 * col)
	{
		c.NB = check_left_places(map, col);
		c.LN = insert_piece(map, c.ia, c.NB, 1);
	}
	print_res(ia, c.NB + 1);
	if (is_winner(map, c.ia, c.NB, c.LN))
		return (1);
	return (0);
}
