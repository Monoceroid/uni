/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:07:57 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/02 13:39:44 by wtaylor          ###   ########.fr       */
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

int	**arrange(int **a, int n, int l, int i)
{
	while (++i < n)
	{
		while (compare_previous(a, i) == 0)
			increment_tet(a[i], l);
		if (a[0][3] > l * l)
			return (NULL);
		if (a[i][3] > l * l)
		{
			i--;
			increment_tet(a[i], l);
			printf("\nI'm about to call the function again.");
			arrange(a, n, l, i);
		}
	}
	return (a);
}
