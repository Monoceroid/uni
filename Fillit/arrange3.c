/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:07:57 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/03 14:38:50 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

int	compare_previous(int **a, int i)
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

int	**clear_tet(int **a, int n, int l, int i)
{
	while (compare_previous(a, i) == 0)
		increment_tet(a[i], l);
	if (a[i][3] > l * l)
	{
//		if (i - 1 > 0 && a[i - 1][3] < l * l)
//		{
			increment_tet(a[i - 1], l);
			zero_all(a + i, n - i, l);
			arrange(a, n, l, i);
//		}
//		else if (i - 2 > 0 && a[i - 2][3] < l * l)
//		{
//			increment_tet(a[i - 2], l);
//			zero_all(a + (i - 1), n - (i - 1), l);
//			arrange(a, n, l, i - 1);
//		}	
//		else if (i - 3 > 0 && a[i - 3][3] < l * l)
//		{
//			increment_tet(a[i - 3], l);
//			zero_all(a + (i - 2), n - (i - 2), l);
//			arrange(a, n, l, i - 2);
//		}	
	}
	return (a);
}

int	**arrange(int **a, int n, int l, int i)
{
	clear_tet(a, n, l, i);
	if (a[0][3] > l * l)
	{
		zero_all(a, n, l);
		l++;
		arrange(a, n, l, i);
	}
	return (a);
}
