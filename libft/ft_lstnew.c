/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkastaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:57:33 by mkastaci          #+#    #+#             */
/*   Updated: 2018/11/20 14:04:39 by mkastaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tt_list;

	tt_list = (t_list *)malloc(sizeof(t_list));
	if (tt_list == NULL)
		return (NULL);
	else
	{
		if (content != NULL)
		{
			tt_list->content = (void *)ft_memalloc(sizeof(void) * \
					content_size + 1);
			if (tt_list->content == NULL)
				return (NULL);
			ft_memcpy(tt_list->content, content, content_size);
			tt_list->content_size = content_size;
		}
		else
		{
			tt_list->content = NULL;
			tt_list->content_size = 0;
		}
		tt_list->next = NULL;
	}
	return (tt_list);
}
