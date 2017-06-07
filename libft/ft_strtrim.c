/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:12:52 by pfrey             #+#    #+#             */
/*   Updated: 2016/12/01 17:33:06 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		stop;
	int		i;

	if (s == NULL)
		return (NULL);
	start = 0;
	stop = ft_strlen(s);
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
	&& s[start] != '\0')
		start++;
	while ((s[stop - 1] == ' ' || s[stop - 1] == '\n' || s[stop - 1] == '\t')
	&& stop > start)
		stop--;
	str = ft_strnew(stop - start);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start < stop)
		str[i++] = s[start++];
	return (str);
}
