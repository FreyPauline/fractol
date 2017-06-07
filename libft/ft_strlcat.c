/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:57:55 by pfrey             #+#    #+#             */
/*   Updated: 2016/12/12 16:49:09 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	size_t		i;

	len = size;
	i = ft_strlen(dst);
	if (size <= i)
		len = i + 1;
	if (size > i)
	{
		ft_strncpy(&dst[i], src, (size - i - 1));
		if (&dst[size - 1])
			dst[size - 1] = '\0';
	}
	if (size <= i)
		return (ft_strlen(src) + size);
	return (i + ft_strlen(src));
}
