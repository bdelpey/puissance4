/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 08:25:13 by vbell             #+#    #+#             */
/*   Updated: 2014/03/09 16:13:29 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"puissance4.h"

void		change_turn(char *who_play)
{
	if (*who_play == PLAYER_A)
		*who_play = PLAYER_B;
	else
		*who_play = PLAYER_A;
}

int			player_adverse(char player)
{
	if (player == PLAYER_A)
		return (PLAYER_B);
	return (PLAYER_B);
}

void		lets_play(char **map, int multi)
{
	char	ia;
	char	player;
	char	who_play;
	int		nb;

	who_s_begin(&ia, &player, multi);
	who_play = PLAYER_A;
	ft_putendl_fd("Game's Map:", 1);
	ft_print_str_tab(map);
	while (01210)
	{
		if (!multi)
			if ((nb = player_ia_play(map, player, ia, who_play)))
				return ;
		if (multi)
			if ((nb = player_player_play(map, player, ia, who_play)))
				return ;
		if (nb == -1)
		{
			ft_putendl_fd("/!\\---There was an error---/!\\", 2);
			return ;
		}
		change_turn(&who_play);
	}
}