/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:37:47 by pfrey             #+#    #+#             */
/*   Updated: 2016/12/12 16:52:15 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*ptr;
	int		len;

	ptr = (char *)big - 1;
	if (!little[0])
		return (++ptr);
	while (*(++ptr))
	{
		len = 0;
		while (*(ptr++) == little[len] && *(ptr - 1) && little[len])
			len++;
		ptr -= (len + 1);
		if (!little[len])
			return (ptr);
	}
	return (NULL);
}
