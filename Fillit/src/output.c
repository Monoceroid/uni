/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:42:03 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/14 13:59:33 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

/*
**	Mallocs an area the size of the square the tetriminos will fit in.
**	Fills that area with '.'. Goes through the solution (a), writing each
**	number as the appropriate letter in the appropriate place in the new
**	area (b).  Writes b to standard output.
*/

void	output(int **a, int n, int l)
{
	int		i;
	int		j;
	char	*b;

	b = malloc(sizeof(char) * l * l);
	i = -1;
	j = -1;
	while (++i < l * l)
		b[i] = '.';
	i = -1;
	while (++i < n)
	{
		while (++j < 4)
			b[a[i][j] - 1] = i + 'A';
		j = -1;
	}
	while (++j < l * l)
	{
		ft_putchar(b[j]);
		if ((j + 1) % l == 0)
			ft_putchar('\n');
	}
}
