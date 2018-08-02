/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1ardif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:39:43 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/02 13:08:36 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_1ardif(int *p, int *q, int n, int count)
{
	int	res;
	int	x;

	res = 1;
	if (p == q)
		return(ft_1arrdif(p, n));
	x = -1;
	if (count == 0)
		return (res);
	while (++x < n)
	{
		if (*p == *(q + x))
			res = 0;
	}
	if (res == 0)
		return (res);
	else
		res = ft_1ardif(p + 1, q, n, count - 1);
	return (res);
}

int	main(void)
{
	int *p;
	int *q;

	p = (int *)malloc(sizeof(int) * 4);
	q = (int *)malloc(sizeof(int) * 4);
	*p = 15;
	*(p + 1) = 16;
	*(p + 2) = 20;
	*(p + 3) = 21;
	*q = 8;
	*(q + 1) = 9;
	*(q + 2) = 10;
	*(q + 3) = 16;
	printf("%d", ft_1ardif(p, q, 4, 4));
	return (0);
}
