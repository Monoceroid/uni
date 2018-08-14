/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:59:11 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/14 13:04:28 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

/*
**	Starts with an initial 'l' (this variable denotes the size of one side of
**	the box) of 4. NOTE: Should start with 2 - needs changing! Then works out
**	what the minimum possible l is based on the number of tetriminos, 'upsizes'
**	those tetriminos (i.e. changes their representations so that they are
**	appropriate for the new l value), and 'zeroes' them (moves them to the top
**	left corner of the box). It then calls the function arrange, which performs
**	the main operation of the program, moving the tetriminos around such that
**	they fit into the smallest possible square. Finally it calls the function
**	output, which outputs the solution to standard output in the correct format.
*/

int		**fillit(int **a, int n)
{
	int	l;
	int	init_l;
	int	*p;

	l = 4;
	p = &l;
	init_l = l;
	while (l * l < 4 * n)
		l++;
	upsize_all(a, l, init_l, n);
	zero_all(a, n, l);
	arrange(a, n, p, 0);
	output(a, n, l);
	return (a);
}

/*
**	Prints usage message if there are not the correct number of arguments.
**	Calls the function validate, which reads the file, stores the tetriminos
**	in a one-dimensional array on the heap, and returns a pointer to that
**	memory area if the file is valid. If it is invalid, validate returns a
**	NULL pointer and 'error' if printed. Next, the libft function ft_12arr
**	is called, which converts the one-dimensional array to a two-dimensional
**	array (not strictly necessary, but makes the manipulation of the tetriminos
**	easier in other functions). Finally, the two-dimensional array is fed to
**	the function fillit, which performs the main task of the program.
*/

int		main(int argc, char **argv)
{
	int		*tets;
	int		n;
	int		**a;

	if (argc != 2)
	{
		ft_putstr("usage: fillit file_name");
		return (0);
	}
	if ((tets = validate(&n, argv)) == NULL)
	{
		ft_putstr("error");
		ft_putchar('\n');
		return (0);
	}
	a = ft_12arr(tets, n * 4, 4);
	a = fillit(a, n);
	return (0);
}
