/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_functs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdelpey <bdelpey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 14:45:53 by bdelpey           #+#    #+#             */
/*   Updated: 2014/03/09 16:05:29 by bdelpey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "puissance4.h"

int					check_block(char **map, char player, int col)
{
	int				nb;
	int				ln;

	nb = 0;
	while (nb < col)
	{
		ln = insert_piece(map, player, nb, 0);
		if (ln != -1 && is_winner(map, player, nb, ln))
			return (nb);
		nb++;
	}
	return (-1);
}

int					check_ia_piece(char **map, char ia)
{
	int				i;
	int				j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ia)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

static int			easy_fork_bis(int i, char **map, char p, int col)
{
	int				j;

	j = 0;
	while (j < col - 4)
	{
		if (map[i][j] == '_' && map[i][j + 1] == p && map[i][j + 2] == '_'
				&& map[i][j + 3] == p && map[i][j + 4] == '_')
			return (j + 2);
		j++;
	}
	return (-1);
}

int					check_easy_fork(char **map, char p, int col)
{
	static int		i = 0;
	int				j;

	if (!i)
		i = ft_len_str_tab(map) - 1;
	j = 0;
	while (j < col - 3)
	{
		if (map[i][j] == '_' && map[i][j + 1] == p && map[i][j + 2] == p
				&& map[i][j + 3] == '_')
		{
			if (j && map[i][j - 1] == '_')
				return (j);
			else if (j + 4 < col && map[i][j + 4] == '_')
				return (j + 3);
		}
		j++;
	}
	return (easy_fork_bis(i, map, p, col));
}

int					default_place(char **map, char ia, int col)
{
	static int		high = 0;

	if (!high)
		high = ft_len_str_tab(map);
	if (!check_ia_piece(map, ia))
		return (col / 2);
	if (map[high - 6][col / 2] == '_')
		return (col / 2);
	if (map[high - 6][col / 2 + 1] == '_')
		return (col / 2 + 1);
	if (map[high - 6][col / 2 - 1] == '_')
		return (col / 2 - 1);
	if (high >= 10)
	{
		if (map[high - 10][col / 2] == '_')
			return (col / 2);
		if (map[high - 10][col / 2 - 1] == '_')
			return (col / 2 - 1);
		if (map[high - 10][col / 2 + 1] == '_')
			return (col / 2 + 1);
	}
	return (col / 2 - 2);
}
