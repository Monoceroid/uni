/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_12arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:13:45 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/22 11:49:51 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_12arr(int *p, int m, int n)
{
	int	i;
	int	j;
	int	k;
	int	**a;

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
			j++;
			k++;
		}
	}
	free(p);
	return (a);
}
