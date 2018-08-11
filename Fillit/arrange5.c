/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:07:57 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/11 13:11:36 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

int		compare_previous(int **a, int i)
{
	int	j;

	j = 0;
	while (i - ++j >= 0)
	{
		if (ft_1ardif(a[i], a[i - j], 4, 4) == 0)
			return (0);
	}
	return (1);
}

//int		**clear_tet(int **a, int n, int l, int i)
//{
//	zero_all(a + i, n - i, l);
//	increment_tet(a[i - 1], l);
//	while (compare_previous(a, i) == 0)
//		increment_tet(a[i], l);
//	return (a);
//}

void	clear_i(int **a, int n, int l, int i)
{
	zero_all(a + i, n - i, l);
	increment_tet(a[i - 1], l);
	while (compare_previous(a, i - 1) == 0)
		increment_tet(a[i - 1], l);
	while (compare_previous(a, i) == 0)
		increment_tet(a[i], l);
}

int		**arrange(int **a, int n, int l, int i)
{
	int	j;
	int	count;
//	int	x;
//	int	y;

	while (++i < n)
	{
		count = 0;
		while (a[0][3] < l * l + 2 && count++ < l * l)
		{
		//	printf("\ni: %i count: %i", i, count);
		//	while (compare_previous(a, i) == 0)
		//		increment_tet(a[i], l);
			j = i + 1;
			while (--j > 0)
			{
			//	printf("\ni: %i, j: %i", i, j);
				zero_all(a + j, n - j, l);
				while (compare_previous(a, j) == 0)
					increment_tet(a[j], l);
//				printf("\na[%i][3]: %i", j, a[j][3]);
				while (a[j][3] > l * l && a[j - 1][3] < l * l + 2)
				{
//					printf("\nj: %i", j);
					clear_i(a, n, l, j);
				}
//				if (i == 3)
//				{
//					printf("\nTets after j = %i loop:\n", j);
//					x = -1;
//					y = -1;
//					while (++x < n)
//					{
//						while (++y < 4)
//							printf(" %d ", a[x][y]);
//						printf("\n");
//						y = -1;
//					}
//				}
				if (a[j - 1][3] < l * l + 1 && j == i)
					break ;
//				printf("\nj: %i", j);
				if (a[j - 1][3] < l * l + 1 && j < i)
					j += 2;
//				printf("\na[0][3]: %i, l*l: %i, j: %i, i: %i: ", a[0][3], l * l, j, i);
				if (a[j - 1][3] > l * l && j > 1)
					clear_i(a, n, l, j - 1);
			}
		}
//		printf("\nTets after i = %i loop:\n", i);
//		x = -1;
//		y = -1;
//		while (++x < n)
//		{
//			while (++y < 4)
//				printf(" %d ", a[x][y]);
//			printf("\n");
//			y = -1;
//		}
		if (a[0][3] > l * l)
		{
			zero_all(a, n, l);
			upsize_all(a, l + 1, l, n);
			l++;
			i = 0;
		}
	}
	printf("\nl: %d\n", l);
	return (a);
}
