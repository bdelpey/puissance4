/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_s_begin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 09:50:03 by vbell             #+#    #+#             */
/*   Updated: 2014/03/09 15:58:47 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<time.h>
#include	"libft.h"
#include	"puissance4.h"

static void	print_begin_a(int multi)
{
	if (multi)
	{
		ft_putstr_fd("Player A starts.\nPlayer A plays with ", 1);
		ft_putendl_fd("\033[1;33mO\033[0;m.", 1);
		ft_putendl_fd("Player B plays with \033[1;31mX\033[0;m.", 1);
	}
	else
	{
		ft_putstr_fd("You start.\nYou play with ", 1);
		ft_putendl_fd("\033[1;33mO\033[0;m.", 1);
		ft_putendl_fd("Ia plays with \033[1;31mX\033[0;m.", 1);
	}
}

static void	print_begin_b(int multi)
{
	if (multi)
	{
		ft_putstr_fd("Player B starts.\nPlayer B plays with ", 1);
		ft_putendl_fd("\033[1;33mO\033[0;m.", 1);
		ft_putendl_fd("Player A plays with \033[1;31mX\033[0;m.", 1);
	}
	else
	{
		ft_putstr_fd("Ia starts.\nIa plays with ", 1);
		ft_putendl_fd("\033[1;33mO\033[0;m.", 1);
		ft_putendl_fd("You play with \033[1;31mX\033[0;m.", 1);
	}
}

void		who_s_begin(char *ia, char *player, int multi)
{
	srand(time(NULL));
	if (rand() % 2)
	{
		*player = PLAYER_A;
		*ia = PLAYER_B;
		print_begin_a(multi);
	}
	else
	{
		*player = PLAYER_B;
		*ia = PLAYER_A;
		print_begin_b(multi);
	}
}
