/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:29:55 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/01 10:39:58 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

c_tet			tet_struct(int *a, int l)
{
	c_tet	tet;

	tet.cdif1 = ((a[1] - 1) % l) - ((a[0] - 1) % l);
	tet.cdif2 = ((a[2] - 1) % l) - ((a[1] - 1) % l);
	tet.cdif3 = ((a[3] - 1) % l) - ((a[2] - 1) % l);
	return (tet);
}

static	void	zero_tet(int *a, int l)
{
	c_tet	old_struct;

	old_struct = tet_struct(a, l);
//	printf("a[0]: %d, a[1]: %d, a[2]: %d, a[3]: %d\n", a[0], a[1], a[2], a[3]);
	while (a[0] > 1)
	{
		a[0]--;
		a[1]--;
		a[2]--;
		a[3]--;
	}
//	printf("a[0]: %d, a[1]: %d, a[2]: %d, a[3]: %d\n", a[0], a[1], a[2], a[3]);
	while (tet_struct(a, l).cdif1 != old_struct.cdif1 || tet_struct(a, l).cdif2
			!= old_struct.cdif2 || tet_struct(a, l).cdif3 != old_struct.cdif3)
	{
		a[0]++;
		a[1]++;
		a[2]++;
		a[3]++;
	}
//	printf("a[0]: %d, a[1]: %d, a[2]: %d, a[3]: %d\n", a[0], a[1], a[2], a[3]);
}

void			zero_all(int **a, int n, int l)
{
	int i;

	i = -1;
	while (++i < n)
	{
//		printf("i: %d, l: %d\n", i, l);
		zero_tet(a[i], l);
	}
}
