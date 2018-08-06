/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:07:57 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/06 13:28:50 by wtaylor          ###   ########.fr       */
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

int	**arrange(int **a, int n, int l, int i)
{
	i = 0;

	while (++i < n)
	{
		while (compare_previous(a, i) == 0)
			increment_tet(a[i], l);
		while (a[i][3] > l * l)
		{
			printf("\nShouldn't go here.");
			clear_i(a, n, l, i);
		}
	}
	return (a);
}
