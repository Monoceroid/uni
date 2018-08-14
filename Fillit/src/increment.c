/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 10:55:08 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/14 14:03:31 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

/*
**	Function to increment a tetrimino (i.e. move it one place to the right/down)
**	whilst retaining its structure. 'c' (not a variable used directly)
**	represents the closeness of a # to the left of the square, and is defined
**	as c = (a[i][j] - 1) % l, where l is the size of one side of the square.
**	c_tet is a struct containing cdif1, cdif2 and cdif3, which are the
**	differences in 'c' between the first and second, second and third, and third
**	and fourth #'s respectively. These three numbers represent a tetrimino's
**	structure. First, every # in a tetrimino is incremented by 1. Then, they are
**	incremented until the new structure is the same as the old structure.
*/

void	increment_tet(int *t, int l)
{
	int		i;
	c_tet	old_struct;

	old_struct = tet_struct(t, l);
	i = -1;
	while (++i < 4)
		t[i]++;
	while (tet_struct(t, l).cdif1 != old_struct.cdif1 || tet_struct(t, l).cdif2
			!= old_struct.cdif2 || tet_struct(t, l).cdif3 != old_struct.cdif3)
	{
		t[0]++;
		t[1]++;
		t[2]++;
		t[3]++;
	}
}
