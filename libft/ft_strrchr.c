/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkastaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:42:11 by mkastaci          #+#    #+#             */
/*   Updated: 2018/11/16 14:31:10 by mkastaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*ft_strrchr(const char *s, int c)
{
	char *cc;

	cc = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			cc = (char*)s;
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	else
		return (cc);
}
