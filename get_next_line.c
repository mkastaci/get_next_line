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

int get_next_line(const int fd, char **line)
{

}


int main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY | O_APPEND, S_IRUSR);
	if (argc > 1)
	{
		printf("%d \n", fd);
	}
return(0);
}
