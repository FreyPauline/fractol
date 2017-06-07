/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:03:45 by pfrey             #+#    #+#             */
/*   Updated: 2016/12/12 16:51:33 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;
	size_t	i;

	b = 0;
	i = 0;
	while (((char *)big)[b] && i < len && ((char *)big)[b])
	{
		l = 0;
		while (((char *)big)[b] == ((char *)little)[l] && \
				((char *)little)[l] && i < len)
		{
			b++;
			l++;
			i++;
		}
		if (!(((char *)little)[l]))
			return (&((char *)big)[b - l]);
		b -= (l - 1);
		i -= (l - 1);
	}
	return (NULL);
}
