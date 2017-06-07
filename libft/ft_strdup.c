/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:59:26 by pfrey             #+#    #+#             */
/*   Updated: 2016/12/12 17:00:13 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if ((s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))) == 0)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
