/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:09:42 by pfrey             #+#    #+#             */
/*   Updated: 2016/12/12 16:50:20 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)(s1 - 1);
	p2 = (unsigned char *)(s2 - 1);
	while ((--n) + 1 && *(++p1) == *(++p2) && *p1 && *p2)
		;
	return (*p1 - *p2);
}
