/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_generic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:43:48 by pfrey             #+#    #+#             */
/*   Updated: 2017/06/02 19:43:53 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(const char *str, int (*function)(int))
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (function(str[i]) && !function(str[i + 1]))
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static char		*ft_word(char const *s, int (*function)(int))
{
	char	*tmp_w;
	int		size;
	int		i;

	size = 0;
	while (!function(s[size]) && s[size])
		size++;
	if (!(tmp_w = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		tmp_w[i] = s[i];
		i++;
	}
	tmp_w[i] = '\0';
	return (tmp_w);
}

char			**ft_strsplit_generic(char const *s, int (*function)(int))
{
	char	**tab;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_count_word(s, function);
	if (!(tab = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	i = -1;
	while (*s)
	{
		while (*s && function(*s))
			s++;
		if (*s && !function(*s))
			tab[++i] = ft_word(s, function);
		while (*s && !function(*s))
			s++;
	}
	tab[++i] = NULL;
	return (tab);
}
