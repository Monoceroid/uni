/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upsize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 10:34:46 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/14 14:36:36 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

/*	Changes the representation of a tetrimino such that it is appropriate for
**	a new value of l (l being the size of one side of the square). For example,
**	#...
**	#...
**	#...
**	#... is represented as 1 5 9 13 when l = 4 (i.e. the row length is 4), but
**	1 6 11 16 when l = 5. You will notice we did nothing to the first element,
**	incremented the second by 1, the third by 2 and the fourth by 3.
**	Generalising this observation gives the condition of our inner while loop.
*/

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
			x = 1;
			count = 0;
		}
		init_l++;
	}
}

/*
**	Calls upsize_tet in a loop until it has been performed for each tetrimino.
*/

void	upsize_all(int **a, int l, int init_l, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		upsize_tet(a[i], l, init_l);
}
