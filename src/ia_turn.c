/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelpey <bdelpey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:25:30 by bdelpey           #+#    #+#             */
/*   Updated: 2014/03/09 17:37:08 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "puissance4.h"

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
	else if ((c->NB = check_block(map, c->player, col)) != -1)
	{
		c->LN = insert_piece(map, c->ia, c->NB, 1);
		write(1, "I BLOCK YOU DUMBASS\n", 20);
		return (1);
	}
	else if ((c->NB = check_easy_fork(map, c->player, col)) != -1)
	{
		c->LN = insert_piece(map, c->ia, c->NB, 1);
		write(1, "YOU THINK I'M THAT DUMB\n", 24);
		return (1);
	}
	else if ((c->NB = check_easy_fork(map, c->ia, col)) != -1)
	{
		c->LN = insert_piece(map, c->ia, c->NB, 1);
		write(1, "TRICKED YOU\n", 12);
		return (1);
	}
	return (0);
}

int					be_smart(char **map, t_cnct *c, int col)
{
	int				fcked;

	fcked = 0;
	c->NB = default_place(map, c->ia, col);
	while (c->LN == -1 && fcked < 2 * col)
	{
		c->LN = insert_piece(map, c->ia, c->NB, 0);
		if ((c->LN > 0 && !is_winner(map, c->player, c->NB, c->LN - 1))
				|| c->LN == 0)
		{
			insert_piece(map, c->ia, c->NB, 1);
			break ;
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
		write(1, "\033[1;33m", 7);
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

	c.player = player;
	c.ia = ia;
	c.LN = -1;
	if (!col)
		col = ft_strlen(map[0]);
	if (starters_check(map, &c, col))
		fcked = 0;
	else
		fcked = be_smart(map, &c, col);
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
