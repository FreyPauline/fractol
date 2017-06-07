/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:41:23 by pfrey             #+#    #+#             */
/*   Updated: 2016/12/08 15:45:54 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isneg(int n)
{
	return ((n < 0) ? 1 : 0);
}

static int		nsize(int n)
{
	int		tmp;
	int		s;

	tmp = n;
	s = 0;
	while (tmp /= 10)
		s++;
	return (s);
}

char			*ft_itoa(int n)
{
	int		neg;
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = isneg(n);
	len = nsize(n) + 2 + neg;
	str = (char*)ft_memalloc((sizeof(char) * len));
	if (str == NULL)
		return (NULL);
	str[--len] = '\0';
	n *= (isneg(n) == 1) ? -1 : 1;
	while (len)
	{
		len--;
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (neg == 1)
		str[len--] = '-';
	return (str);
}
