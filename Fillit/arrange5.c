/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:07:57 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/10 10:18:02 by wtaylor          ###   ########.fr       */
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

	count = 0;
	while (++i < n)
	{
		while (a[0][3] < l * l + 2 && count++ < l * l)
		{	
		//	printf("\ni: %i count: %i", i, count);
			while (compare_previous(a, i) == 0)
				increment_tet(a[i], l);
			j = i + 1;
			while (--j > 0)
			{
				while (a[j][3] > l * l && a[j - 1][3] < l * l + 2)
				{
					printf("\nj: %i", j);
					clear_i(a, n, l, j);
				}
				if (a[j - 1][3] < l * l + 1)
					break ;
			}
		}
		count = 0;
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
