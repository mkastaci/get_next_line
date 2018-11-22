/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkastaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:47:12 by mkastaci          #+#    #+#             */
/*   Updated: 2018/11/16 14:29:14 by mkastaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_dst;
	const char	*tmp2_src;

	tmp_dst = dst;
	tmp2_src = src;
	if (len <= 0)
		return (dst);
	if (tmp_dst < tmp2_src)
	{
		while (len-- > 0)
			*tmp_dst++ = *tmp2_src++;
	}
	else
	{
		tmp_dst += len;
		tmp2_src += len;
		while (len-- > 0)
			*--tmp_dst = *--tmp2_src;
	}
	return (dst);
}
