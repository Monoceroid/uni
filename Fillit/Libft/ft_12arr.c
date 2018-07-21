/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_12arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:13:45 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/21 13:09:56 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_12arr(int *p, int m, int n)
{
	int	i;
	int	j;
	int	k;
	int	**a;

	i = 0;
	j = 0;
	k = 0;
	a = (int **)malloc(sizeof(int *) * (m / n));
	a[0] = (int *)malloc(sizeof(int) * m);
	while (i < (m / n))
	{
		a[i] = a[0] + n * i;
		i++;
	}
	i = 0;
	while (i < (m / n))
	{
		while (j < n)
		{
			a[i][j] = p[k];
			j++;
			k++;
		}
		i++;
		j = 0;
	}
	return (a);	
}
