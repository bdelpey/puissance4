/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 12:00:27 by vbell             #+#    #+#             */
/*   Updated: 2014/03/09 08:52:13 by vbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<sys/types.h>
#include			<sys/uio.h>
#include			<unistd.h>
#include			<stdlib.h>
#include			"libft.h"
#include			"get_next_line.h"

static int			is_an_eol(char *buf, char **line, int *i)
{
	int				k;
	int				size;

	k = *i;
	while (buf[*i] != '\0')
	{
		if (buf[*i] == '\n')
		{
			buf[*i] = '\0';
			size = ft_strlen(*line) + ft_strlen(&buf[k]) + 1;
			*line = ft_realloc(*line, size);
			*line = ft_strcat(*line, &buf[k]);
			*i = *i + 1;
			return (1);
		}
		*i = *i + 1;
	}
	*i = 0;
	*line = ft_strcat(*line, buf);
	return (0);
}

static int			End_of_file(char **line)
{
		if (ft_strlen(*line) == 0)
		{
			free(*line);
			return (0);
		}
		else
			return (1);
}

static int			is_no_eol(int const fd, char *buf, char **line, int *i)
{
	int			k;
	int			ret;
	int			size;

	k = 1;
	while (ft_strchr(&buf[*i], '\n') == NULL)
	{
		size = ft_strlen(*line) + ft_strlen(&buf[*i]) + 1;
		*line = ft_realloc(*line, size);
		*line = ft_strcat(*line, &buf[*i]);
		++k;
		if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
		{
			*i = 0;
			return (End_of_file(line));
		}
		if (ret < 0)
		{
			free(*line);
			return (-1);
		}
		buf[ret] = '\0';
		*i = 0;
	}
	return (2);
}

int					get_next_line(int const fd, char **line)
{
	static int		ret = 0;
	static char		buf[BUFF_SIZE + 1];
	static int		i = 0;
	int				Eol;

	if ((*line = ft_strnew(1)) == NULL)
		return (-1);
	if (i == 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
		{
			free(*line);
			return (ret);
		}
		buf[ret] = '\0';
	}
	Eol = is_no_eol(fd, buf, line, &i);
	if (Eol == 1 || Eol == 0)
		return (Eol);
	if (Eol == -1)
		return (-1);
	if (is_an_eol(buf, line, &i) == 1)
		return (1);
	return (1);
}
