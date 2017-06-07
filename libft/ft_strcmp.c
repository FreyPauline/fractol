/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:07:23 by pfrey             #+#    #+#             */
/*   Updated: 2016/12/12 16:47:16 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)(s1 - 1);
	p2 = (unsigned char *)(s2 - 1);
	while (*(++p1) == *(++p2) && *p1 && *p2)
		;
	return (*p1 - *p2);
}
