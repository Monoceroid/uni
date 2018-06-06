/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:59:23 by wtaylor           #+#    #+#             */
/*   Updated: 2018/06/06 16:25:38 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int a)
{
	int	l;

	l = 0;
	if (a == 0)
		return (1);
	while (a > 0)
	{
		a = a / 10;
		l++;
	}
	return (l);
}

static int	power(int a)
{
	int	b;

	if (a == 0)
		return (1);
	b = 10;
	while (a > 1)
	{
		b = b * 10;
		a--;
	}
	return (b);
}

char		*ft_itoa(int n)
{
	int		i;
	int		l;
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		l = length(n);
		if ((s = ft_strnew(l + 1)) == NULL)
			return (NULL);
		s[0] = ('-');
		i = 1;
	}
	else
	{
		l = length(n);
		if ((s = ft_strnew(l)) == NULL)
			return (NULL);
		i = 0;
	}
	while (--l >= 0)
		s[i++] = ((n / power(l)) % 10 + 48);
	return (s);
}
