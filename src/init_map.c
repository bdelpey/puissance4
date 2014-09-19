/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 07:54:58 by vbell             #+#    #+#             */
/*   Updated: 2014/03/09 16:40:09 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<errno.h>
#include	<stdlib.h>
#include	"libft.h"
#include	"puissance4.h"

static char	**fill_map(int ln, int col)
{
	char	**map;
	int		i;
	int		j;

	if ((map = (char **)malloc(sizeof(char *) * (ln + 1))) == NULL)
	{
		strerror(errno);
		return (NULL);
	}
	i = -1;
	while (++i < ln)
	{
		j = -1;
		if ((map[i] = (char *)malloc(sizeof(char) * (col + 1))) == NULL)
		{
			strerror(errno);
			return (NULL);
		}
		while (++j < col)
			map[i][j] = EMPTY_CAR;
		map[i][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

static void	ft_error_syntax(void)
{
	ft_putstr_fd("Usage: ./puissance4 [--multi]", 2);
	ft_putendl_fd(" [nb_line > 5] [nb_col > 6]", 2);
	ft_putendl_fd("\t--multi\t\t: allow the multiplayer mode", 2);
}

char		**init_map(int ac, char **av, int *player)
{
	char	**map;
	int		ln;
	int		col;

	map = NULL;
	if (ac >= 3)
	{
		if (!ft_strcmp(av[*player + 1], "--multi"))
			(*player)++;
		if (is_num(av[*player + 1]) && is_num(av[*player + 2]))
		{
			ln = ft_atoi(av[*player + 1]);
			col = ft_atoi(av[*player + 2]);
			if (ln >= MIN_LINE && col >= MIN_COL)
				if ((map = fill_map(ln, col)) != NULL)
					return (map);
		}
	}
	ft_error_syntax();
	return (map);
}
