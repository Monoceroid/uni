/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:07:57 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/14 14:01:08 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

/*
**	Compares the ith tetrimino against all previous tetriminos (i.e. a[2] would
**	be compared against a[1] and a[0]) using the libft function ft_1ardif, which
**	compares two arrays to see if any element is the same, returning 0 if so and
**	1 if all are different.
*/

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

/*
**	Increments the (i-1)th tetrimino, moves it clear of any previous tetriminos,
**	then moves the ith tetrimino clear.
*/

void	clear_i(int **a, int n, int l, int i)
{
	zero_all(a + i, n - i, l);
	increment_tet(a[i - 1], l);
	while (compare_previous(a, i - 1) == 0)
		increment_tet(a[i - 1], l);
	while (compare_previous(a, i) == 0)
		increment_tet(a[i], l);
}

/*
**	This is where the core fillit algorithm is. The outermost loop does the
**	operation on each tetrimino. The next loop in ends when the 0th tetrimino
**	has exceeded the limits of the current square, in which case we increase
**	the size of the square, or when we have repeated the operation enough times
**	that we can be sure the 0th tetrimino is not going to exceed the limits
**	(i.e. whichever tetrimino we are working on, and all previous ones, have
**	found a place inside the square). The innermost loop uses the variable j,
**	which is initially a copy of i. We start by moving the tetrimino we are
**	working on clear of previous tetriminos. If its last element has exceeded
**	the bounds of the square, we call 'clear_i', which increments the previous
**	tetrimino by 1, then tries to find a place for both tetriminos. If this
**	process ends up with that earlier tetrimino exceeding the bounds of the
**	square, we call 'clear_i' again for the tetrimino before it, and so on.
**	If at any point both the ith tetrimino and the previous one are within
**	the bounds of the square, we break out of the loop, ready to move on to
**	the next tetrimino. If the jth tetrimino and the previous one are within
**	the square, we increase j again, aiming to get the ith tetrimino (the one
**	we were working on when we entered the loop) inside the square.
*/

int     **arrange(int **a, int n, int *l, int i)
{   
    int j;
    int count;

    while (++i < n)
    {
        count = 0;
        while (a[0][3] < *l * *l + 2 && count++ < *l * *l)
        {
            j = i + 1;
            while (--j > 0)
            {
                zero_all(a + j, n - j, *l);
                while (compare_previous(a, j) == 0)
                    increment_tet(a[j], *l);
                while (a[j][3] > *l * *l && a[j - 1][3] < *l * *l + 2)
                    clear_i(a, n, *l, j);
                if (a[j - 1][3] < *l * *l + 1 && j == i)
                    break ;
                if (a[j - 1][3] < *l * *l + 1 && j < i)
                    j += 2;
                if (a[j - 1][3] > *l * *l && j > 1)
                    clear_i(a, n, *l, j - 1);
            }
        }
        if (a[0][3] > *l * *l)
        {
            zero_all(a, n, *l);
            upsize_all(a, *l + 1, *l, n);
            (*l)++;
            i = 0;
        }   
    }
    return (a);
