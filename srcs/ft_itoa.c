/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:29:47 by wtaylor           #+#    #+#             */
/*   Updated: 2018/05/19 20:40:48 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		o;
	size_t	size;
	char	*s;
	size_t	i;

	if (n < 0)
		o = n * -1;
	else
		o = n;
	size = 0;
	while (o >= 1)
	{
		o = o / 10;
		size++;
	}
	s = ft_strnew((size + 1) * sizeof(s));
	i = size;
	while (i > 0)
	{
		s[i] = n % 10;
		n = n / 10;
		i--;
	}
	return (s);
}
