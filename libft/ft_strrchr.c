/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:42:58 by pfrey             #+#    #+#             */
/*   Updated: 2016/12/12 16:51:49 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		len;

	len = 0;
	ptr = (char *)s;
	while (*(ptr++) != '\0' && ++len)
		;
	if (c == '\0')
		return (--ptr);
	while (--len > -2)
	{
		if (*(--ptr) == c)
			return (ptr);
	}
	return (NULL);
}
