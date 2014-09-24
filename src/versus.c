/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   versus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 16:13:08 by vbell             #+#    #+#             */
/*   Updated: 2014/09/24 15:56:24 by bdelpey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"puissance4.h"

static int	is_equality(char **map)
{
	if (!ft_strchr(map[0], EMPTY_CAR))
	{
		ft_putendl_fd("Game's Map:", 1);
		ft_print_str_tab(map);
		ft_putendl_fd("Draw!", 1);
		return (1);
	}
	return (0);
}

int			player_ia_play(char **map, char player, char ia, char who_play)
{
	int		nb;

	if (is_equality(map))
		return (1);
	if (who_play == ia)
	{
		if ((nb = ia_turn(map, ia, player)))
		{
			ft_putendl_fd("Game's Map:", 1);
			ft_print_str_tab(map);
			ft_putendl_fd("Ia win, what did you expect? :p", 1);
		}
	}
	else
	{
		ft_putendl_fd("Game's Map:", 1);
		ft_print_str_tab(map);
		if ((nb = player_turn(map, player, 0)))
		{
			ft_putendl_fd("Game's Map:", 1);
			ft_print_str_tab(map);
			ft_putendl_fd("You win!", 1);
		}
	}
	return (nb);
}

int			player_player_play(char **map, char p1, char p2, char who_play)
{
	int		nb;

	if (is_equality(map))
		return (1);
	ft_putendl_fd("Game's Map:", 1);
	ft_print_str_tab(map);
	if (who_play == p1)
	{
		if ((nb = player_turn(map, p1, 1)))
		{
			ft_putendl_fd("Game's Map:", 1);
			ft_print_str_tab(map);
			ft_putendl_fd("Player A win!", 1);
		}
	}
	else
	{
		if ((nb = player_turn(map, p2, 1)))
		{
			ft_putendl_fd("Game's Map:", 1);
			ft_print_str_tab(map);
			ft_putendl_fd("Player B win!", 1);
		}
	}
	return (nb);
}

int			ia_ia_play(char **map, char ia1, char ia2, char who_play)
{
	int		nb;

	if (is_equality(map))
		return (1);
	if (who_play == ia1)
	{
		if ((nb = ia_turn(map, ia1, ia2)))
		{
			ft_putendl_fd("Game's Map:", 1);
			ft_print_str_tab(map);
			ft_putendl_fd("Ia1 win!", 1);
		}
	}
	else
	{
		if ((nb = ia_turn(map, ia2, ia1)))
		{
			ft_putendl_fd("Game's Map:", 1);
			ft_print_str_tab(map);
			ft_putendl_fd("Ia2 win!", 1);
		}
	}
	return (nb);
}

