/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:29:55 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/14 14:31:50 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*	c_tet is a struct which represents a tetrimino's structure.
**	'c' (not a variable used directly) represents the closeness of a # to
**	the left of the square, and is defined as c = (a[i][j] - 1) % l, where
**	l is the size of one side of the square. cdif1, cdif2 and cdif3  are the
**	differences in 'c' between the first and second, second and third, and
**	third and fourth #'s respectively.
*/

c_tet			tet_struct(int *a, int l)
{
	c_tet	tet;

	tet.cdif1 = ((a[1] - 1) % l) - ((a[0] - 1) % l);
	tet.cdif2 = ((a[2] - 1) % l) - ((a[1] - 1) % l);
	tet.cdif3 = ((a[3] - 1) % l) - ((a[2] - 1) % l);
	return (tet);
}

/*
**	This function 'zeroes' a tetrimino, i.e. it moves it to the top left
**	of the square. The first loop subtracts 1 from each element until the
**	first element is at position zero. The second acknowledges that doing
**	so may have broken the structure of the tetrimino, and fixes it by
**	adding 1 to each element until the structure, as explained above,
**	is restored.
*/

static	void	zero_tet(int *a, int l)
{
	c_tet	old_struct;

	old_struct = tet_struct(a, l);
	while (a[0] > 1)
	{
		a[0]--;
		a[1]--;
		a[2]--;
		a[3]--;
	}
	while (tet_struct(a, l).cdif1 != old_struct.cdif1 || tet_struct(a, l).cdif2
			!= old_struct.cdif2 || tet_struct(a, l).cdif3 != old_struct.cdif3)
	{
		a[0]++;
		a[1]++;
		a[2]++;
		a[3]++;
	}
}

/*
**	Calls zero_tet in a loop until it has been applied to each tetrimino.
*/

void			zero_all(int **a, int n, int l)
{
	int i;

	i = -1;
	while (++i < n)
		zero_tet(a[i], l);
}
