/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:19:39 by pfrey             #+#    #+#             */
/*   Updated: 2016/12/12 16:41:38 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	while (n--)
	{
		if ((*(pdst++) = *(psrc++)) == (unsigned char)c)
			return (pdst);
	}
	return (NULL);
}
