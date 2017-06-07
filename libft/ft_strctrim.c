/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:52:04 by pfrey             #+#    #+#             */
/*   Updated: 2016/12/02 18:02:16 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char const *s, char c)
{
	char	*str;
	int		start;
	int		i;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (s[start] == c)
		start++;
	str = ft_strnew(ft_strlen(s) - start);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start < (int)ft_strlen(s))
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
