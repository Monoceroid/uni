/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdiff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:54:47 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/22 10:00:14 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_arrdiff(int **p, int m, int n)
{
	int	i;
	int	x;
	int **q;

	i = 0;
	x = 1;
	q = p;
	while (i < (m * n))
	{
		while (x < (m * n - x + 1 - (p - q)))
		{
			if (**p == **(p + x))
				return (0);
			x++;
		}
		p++;
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
	printf("%d", ft_arrdiff(arr, 3, 4));
	return (0);
}
