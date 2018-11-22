/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkastaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:23:34 by mkastaci          #+#    #+#             */
/*   Updated: 2018/11/16 14:32:35 by mkastaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_size_long(int neg, long res, char c)
{
	long tmp;

	tmp = res;
	res = res * 10 + (c - '0') * neg;
	if (neg == 1 && res < tmp)
		return (-2);
	else if (neg == -1 && res > tmp)
	{
		return (-1);
	}
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (check_size_long(neg, res, str[i]) < 0)
			return (check_size_long(neg, res, str[i]) + 1);
		res = res * 10 + (str[i] - '0') * neg;
		i++;
	}
	return ((int)res);
}
