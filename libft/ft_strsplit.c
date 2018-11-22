/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkastaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:55:09 by mkastaci          #+#    #+#             */
/*   Updated: 2018/11/16 16:16:10 by mkastaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbmot(char *s, char c)
{
	int		i;
	int		mot;

	i = 0;
	mot = 0;
	while (*s)
	{
		if (mot == 0 && *s != c)
		{
			mot = 1;
			i++;
		}
		else if (mot == 1 && *s == c)
			mot = 0;
		s++;
	}
	return (i);
}

static int	ft_strlenlim(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb_ofwords;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	nb_ofwords = ft_nbmot((char *)s, c);
	tab = (char **)malloc(sizeof(char*) * (nb_ofwords + 1));
	i = 0;
	if (!tab)
		return (NULL);
	while (nb_ofwords--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((char *)s, 0, ft_strlenlim((char *)s, c));
		if (!tab[i])
			return (NULL);
		s = s + ft_strlenlim((char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
