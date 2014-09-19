/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 09:51:15 by vbell             #+#    #+#             */
/*   Updated: 2014/03/09 17:57:16 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>
#include	"libft.h"
#include	"puissance4.h"

static int	player_play(char **map, char *line, char player, int *ln)
{
	char	*tmp;
	int		nb;

	tmp = ft_strtrim(line);
	if ((nb = check_player_entry(map, line)) != -1)
	{
		if (tmp)
			free(tmp);
		if ((*ln = insert_piece(map, player, nb - 1, 1)) == -1)
			ft_putendl_fd(COL_ERR, 2);
		else
			return (nb);
	}
	else
	{
		if (tmp)
			free(tmp);
		ft_putendl_fd(COL_ERR, 2);
	}
	return (-1);
}

static void	print_player(char player, int multi, int begin)
{
	if (player == PLAYER_B)
		write(1, "\033[1;31m", 7);
	if (player == PLAYER_A)
		write(1, "\033[1;33m", 7);
	write(1, &player, 1);
	write(1, "\033[0;m", 5);
	if (multi && player == PLAYER_B && begin)
		ft_putstr_fd(": It's the turn of Player B, enter a number: ", 1);
	else if (multi && player == PLAYER_A && begin)
		ft_putstr_fd(": It's the turn of Player A, enter a number: ", 1);
	else if (begin)
		ft_putstr_fd(": It's your turn, enter a number: ", 1);
}

static void	print_res(char multi, char player, int nb)
{
	if (player == PLAYER_B)
		write(1, "\033[1;31m", 7);
	if (player == PLAYER_A)
		write(1, "\033[1;33m", 7);
	ft_putstr_fd("-- ", 1);
	write(1, "\033[0;m", 5);
	if (multi)
	{
		if (player == PLAYER_B)
			ft_putstr_fd("Player B Played in ", 1);
		else if (player == PLAYER_A)
			ft_putstr_fd("Player A Played in ", 1);
	}
	else
		ft_putstr_fd("You Played in ", 1);
	ft_putnbr_fd(nb, 1);
	ft_putendl_fd("", 1);
}

int			player_turn(char **map, char player, int multi)
{
	char	*line;
	int		nb;
	int		ln;

	nb = -1;
	print_player(player, multi, 1);
	while (get_next_line(0, &line) > 0)
	{
		nb = player_play(map, line, player, &ln);
		free(line);
		if (nb != -1)
			print_res(multi, player, nb);
		if (nb != -1 && is_winner(map, player, nb - 1, ln))
			return (1);
		else if (nb != -1)
			return (0);
		ft_putendl_fd("Game's Map:", 1);
		ft_print_str_tab(map);
		print_player(player, multi, 0);
		ft_putstr_fd(": Try again, enter a number: ", 1);
	}
	return (-1);
}
