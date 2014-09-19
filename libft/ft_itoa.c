/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 07:36:20 by vbell             #+#    #+#             */
/*   Updated: 2013/12/03 09:33:18 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<string.h>
#include			<stdlib.h>

size_t				ft_strlen(char const *s);

static void			ft_str_reverse(char *str)
{
	size_t			i;
	size_t			ln_str;
	char			c;

	i = 0;
	ln_str = ft_strlen(str) - 1;
	while (i < ln_str)
	{
		c = str[i];
		str[i] = str[ln_str];
		str[ln_str] = c;
		i++;
		ln_str--;
	}
}

static int			nb_ln(int n)
{
	int				ln;

	ln = 1;
	while (n != 0)
	{
		ln++;
		n = n / 10;
	}
	return (ln);
}

static void			ft_nb_neg(int *n, int *i, char *tab)
{
	if (*n < 0)
	{
		if (*n == -2147483648)
		{
			tab[0] = '8';
			tab[1] = '\0';
			*n = 214748364;
			*i = *i + 1;
		}
		else
			*n = -*n;
	}
}

char				*ft_itoa(int n)
{
	int			i;
	int			nb;
	char		*strnb;

	strnb = (char *)malloc(sizeof(int) * nb_ln(n) + 1);
	i = 0;
	nb = n;
	ft_nb_neg(&nb, &i, strnb);
	if (nb == 0)
		strnb[i] = '0';
	while (nb > 0)
	{
		strnb[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	if (n < 0)
		strnb[i] = '-';
	if (n < 0 || n == 0)
		i++;
	strnb[i] = '\0';
	ft_str_reverse(strnb);
	return (strnb);
}
