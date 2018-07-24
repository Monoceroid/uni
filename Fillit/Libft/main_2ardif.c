/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2ardif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:56:56 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/23 15:13:26 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_2ardif(int **a, int r, int c)
{
	int res;
	int x;

	res = 1;
	x = 0;
	if (r == 1)
		return (res);
	while (++x < r)
	{
		if (ft_1ardif(*a, *(a + x), c, c) == 0)
			res = 0;
	}
	if (res == 0)
		return (res);
	else
		res = ft_2ardif(a + 1, r - 1, c);
	return (res);
}

int	main(void)
{
	int	i;
	int	j;
	int	count;
	int **a;

	a = (int **)malloc(sizeof(int *) * 4);
	a[0] = (int *)malloc(sizeof(int) * 16);
	i = -1;
	while (++i < 4)
		a[i] = a[0] + 4 * i;
	count = 1;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			a[i][j] = count++;
		}
	}
	a[2][1] = 12;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			printf("%d, ", a[i][j]);
		}
		printf("\n");
	}
	printf("%d", ft_2ardif(a, 4, 4));
	return (0);
}
