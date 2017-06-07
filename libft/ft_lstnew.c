/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:39:09 by pfrey             #+#    #+#             */
/*   Updated: 2016/12/13 11:41:02 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	newlist->next = NULL;
	newlist->content = NULL;
	if (!content)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
		return (newlist);
	}
	if (!(newlist->content = malloc(content_size)))
		return (NULL);
	ft_memcpy(newlist->content, (void *)content, content_size);
	newlist->content_size = content_size;
	return (newlist);
}
