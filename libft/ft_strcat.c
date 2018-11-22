/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkastaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:40:42 by mkastaci          #+#    #+#             */
/*   Updated: 2018/11/16 14:29:27 by mkastaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int i;
	unsigned int ii;

	i = 0;
	ii = 0;
	while (s1[i])
		i++;
	while (s2[ii])
	{
		s1[i] = s2[ii];
		i++;
		ii++;
	}
	s1[i] = '\0';
	return (s1);
}
