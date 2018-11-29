/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkastaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:21:06 by mkastaci          #+#    #+#             */
/*   Updated: 2018/11/29 17:58:49 by mkastaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 32

typedef struct		s_getlist
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;
}					t_getlist;

int					get_next_line(const int fd, char **line);
#endif
