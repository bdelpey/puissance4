/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 07:16:49 by vbell             #+#    #+#             */
/*   Updated: 2014/03/09 17:59:09 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"puissance4.h"

int			main(int ac, char **av)
{
	char	**map;
	int		multi;

	map = 0;
	multi = 0;
	if ((map = init_map(ac, av, &multi)) == 0)
		return (-1);
	ft_putendl_fd("-- The game just begin let's go!", 1);
	lets_play(map, multi);
	ft_putendl_fd("-- The game is over.", 1);
	ft_free_str_tab(map);
	return (0);
}
