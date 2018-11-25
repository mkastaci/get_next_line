/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkastaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:16:35 by mkastaci          #+#    #+#             */
/*   Updated: 2018/11/22 16:55:16 by mkastaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

char	*lirefichier(int fd, char *str)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char *str;
	int i;
	int g;

	g = 0;
	i = 0;
	if (fd == -1 || line == NULL)
		return (-1);
	if (str == NULL)
	{
		if (!(str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	}
	str = lirefichier(fd, str);
	if (str[i])
	{
		while (str[i] != '\n' && str[i] != '\n')
			i++;
		if (i == 0)
			(*line) = ft_strdup("");
		else
		{
			(*line) = ft_strsub(str, 0, i);
			str = &str[i + 1];
		}
		printf("%s \n", line[g]);
		g++;
		return (1);
	}
	else
		(*line) = ft_strdup("");
	return (0);
}


int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			free(line);
		}
	}
	else
		write(2, "il manque largument\n", 19);
	return (0);
}
