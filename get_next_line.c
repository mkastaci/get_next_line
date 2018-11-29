/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkastaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:16:35 by mkastaci          #+#    #+#             */
/*   Updated: 2018/11/29 17:59:39 by mkastaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int		line_return(char **line, char **c, int ret)
{
	char *tmp;

	if (*c != NULL)
	{
		tmp = *line;
		*line = (*line == NULL) ? ft_strdup(*c) : ft_strjoin(*line, *c);
		if (*line != NULL)
			free(tmp);
		ft_strdel(c);
		return (1);
	}
	else
	{
		if (ret < 0)
			return (-1);
		else if (!*line)
			return (0);
		else if (ret == 0 && **line)
			return (1);
		return (ret);
	}
	return (0);
}

int		check_str(char **line, char **str)
{
	char *stop;
	char *tmp;

	stop = NULL;
	if ((stop = ft_strchr(*str, '\n')) != NULL)
	{
		*line = ft_strsub(*str, 0, stop - *str);
		tmp = *str;
		*str = ft_strdup(stop + 1);
		free(tmp);
		return (1);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
		return (0);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char *str = NULL;
	t_getlist	l;

	l.tmp = NULL;
	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (str != NULL)
		if (check_str(line, &str))
			return (1);
	while ((l.ret = read(fd, l.buff, BUFF_SIZE)) > 0)
	{
		l.buff[l.ret] = '\0';
		if ((l.tmp = ft_strchr(l.buff, '\n')) != NULL)
			break ;
		l.tmp = *line;
		*line = (*line == NULL) ? ft_strdup(l.buff) : ft_strjoin(*line, l.buff);
		if (*line != NULL)
			free(l.tmp);
	}
	str = (l.tmp && *l.tmp == '\n') ? ft_strdup(l.tmp + 1) : str;
	l.tmp = (l.tmp && *l.tmp == '\n') ?
		ft_strsub(l.buff, 0, l.tmp - l.buff) : NULL;
	return (line_return(line, &l.tmp, l.ret));
}
