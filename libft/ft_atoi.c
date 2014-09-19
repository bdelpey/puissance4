/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:32:24 by vbell             #+#    #+#             */
/*   Updated: 2014/02/24 16:16:26 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int			ft_isdigit(int c);
char		*ft_strtrim(char *s);

static void	ft_init_atoi_var(int *i, int *min, int *nb)
{
	*min = 0;
	*nb = 0;
	*i = 0;
}

int			ft_atoi(const char *str)
{
	int		nb;
	char	*tmp;
	int		min;
	int		i;

	ft_init_atoi_var(&i, &min, &nb);
	tmp = ft_strtrim((char *)str);
	if (tmp[i] == '-')
	{
		min = 1;
		i++;
	}
	else if (tmp[i] == '+')
		i++;
	while (ft_isdigit(tmp[i]) != 0)
	{
		nb = nb * 10;
		nb = nb + (int)(tmp[i] - 48);
		i++;
	}
	if (min == 1)
		nb = -nb;
	free(tmp);
	return (nb);
}
