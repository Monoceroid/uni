/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 10:03:53 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/22 11:50:38 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int **ft_12arr(int *p, int m, int n)
{
	int i;
	int j;
	int k;
	int **a;

	a = (int **)malloc(sizeof(int *) * (m / n));
	a[0] = (int *)malloc(sizeof(int) * m);
	i = -1;
	while (++i < (m / n))
		a[i] = a[0] + n * i;
	i = -1;
	k = 0;
	while (++i < (m / n))
	{
		j = 0;
		while (j < n)
		{
			a[i][j] = p[k];
			printf("%d (%d %d), ", a[i][j], i, j);
			j++;
			k++;
		}
		printf("\n");
	}
	printf("\n");
	free(p);
	return (a);
}

int	main(void)
{
	int r;
	int	c;
	int *arr;
	int count;
	int	i;
	int	j;
	int	**res;

	count = 0;
	i = -1;
	j = -1;
	arr = (int *)malloc(sizeof(int) * 12);
	while (++i < 12)
		arr[i] = (++count);
	r = 4;
	c = 3;
	res = ft_12arr(arr, (r * c), c);
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < c)
			printf("%d (%d %d) ", res[i][j], i, j);
		printf("\n");
	}
	return (0);
}
