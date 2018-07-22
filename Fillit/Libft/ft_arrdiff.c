/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdiff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:54:47 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/22 12:55:04 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_arrdiff(int **p, int r, int c)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++x < r)
	{
		while (++y < c)
		{
			if (y < (c - 1))
			{
				i = x - 1;
				j = y;
			}
			else
			{
				i = x;
				j = -1;
			}
			while (++i < r)
			{
				while (++j < c)
				{
					if (p[x][y] == p[i][j])
						return (0);
				}
				j = -1;
			}
		}
		y = -1;
	}
	return (1);
}

int	main(void)
{

	int r=3, c=4;
	int **arr;
	int count = 0,i,j;

	arr  = (int **)malloc(sizeof(int *) * r);
	arr[0] = (int *)malloc(sizeof(int) * c * r);

	for(i = 0; i < r; i++)
		arr[i] = (*arr + c * i);

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			arr[i][j] = ++count;
//	arr[0][1] = 10;
	for (i = 0; i <  r; i++)
		for (j = 0; j < c; j++)
			printf("%d ", arr[i][j]);
	printf("\n%d", ft_arrdiff(arr, 3, 4));
	return (0);
}
