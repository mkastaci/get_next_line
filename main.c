/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkastaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:21:10 by mkastaci          #+#    #+#             */
/*   Updated: 2018/11/26 19:25:46 by mkastaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	return (0);
}
