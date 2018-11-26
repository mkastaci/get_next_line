/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkastaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:16:35 by mkastaci          #+#    #+#             */
/*   Updated: 2018/11/26 19:19:29 by mkastaci         ###   ########.fr       */
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
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	tmp = NULL;
	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (str != NULL)
		if (check_str(line, &str))
			return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((tmp = ft_strchr(buff, '\n')) != NULL)
			break ;
		tmp = *line;
		*line = (*line == NULL) ? ft_strdup(buff) : ft_strjoin(*line, buff);
		if (*line != NULL)
			free(tmp);
	}
	str = (tmp && *tmp == '\n') ? ft_strdup(tmp + 1) : str;
	tmp = (tmp && *tmp == '\n') ? ft_strsub(buff, 0, tmp - buff) : NULL;
	return (line_return(line, &tmp, ret));
}

/*
int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int ret;

	line = NULL;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
	}
	else
		write(2, "il manque largument\n", 19);
	while (1);
	return (0);
}*/
