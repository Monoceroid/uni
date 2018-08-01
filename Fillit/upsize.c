/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upsize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 10:34:46 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/01 10:36:40 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

void	upsize_tet(int *a, int l, int init_l)
{
	int	i;
	int	x;
	int	count;

	while (init_l < l)
	{
		count = 0;
		i = -1;
		x = 1;
		while (++i < 4)
		{
			while (a[i] > init_l * x)
			{
				count++;
				x++;
			}
			a[i] += count;
//			printf("a[%d]: %d\n", i, a[i]);
			x = 1;
			count = 0;
		}
		init_l++;
//		printf("init_l: %d\n", init_l);
	}
}

void	upsize_all(int **a, int l, int init_l, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		upsize_tet(a[i], l, init_l);
}
