/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1ardif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:39:43 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/23 12:54:45 by wtaylor          ###   ########.fr       */
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
		x = 0;
	else
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

	int n;
	int *p;
	int	*q;
	int count;
	int	i;

	n = 12;
	p  = (int *)malloc(sizeof(int ) * n);
	count = 1;
	i = 0;
	while (i < 12)
		p[i++] = count++;
	q  = (int *)malloc(sizeof(int ) * n);
	count = 13;
	i = 0;
	while (i < 12)
		q[i++] = count++;
	q[11] = 12;
	i = 0;
	while (i < 12)
		printf("%d ", p[i++]);
	printf("\n");
	i = 0;
	while (i < 12)
		printf("%d ", q[i++]);
	printf("\n%d", ft_1ardif(p, q, 12, 12));
	return (0);
}
