/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:59:11 by wtaylor           #+#    #+#             */
/*   Updated: 2018/08/02 11:42:10 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		**fillit(int **a, int n)
{
	int	l;
	int	init_l;

	l = 4;
	init_l = l;
	while (l * l < 4 * n)
		l++;
	upsize_all(a, l, init_l, n);
	zero_all(a, n, l);
	return (arrange(a, n, l, 0));
}

int		main(int argc, char **argv)
{
	int		*tets;
	int		n;
	int		**testvariable;
	int		i;
	int		j;

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
	//	printf("%d\n", tets[16]);
	printf("Number of tets: %d\n", n);
	//	printf("cdif1: %d\n", (tet_struct(tets, 4)).cdif1);
	//	zero_tet(tets, 4);
	//	printf("Zeroed tet element: %d\n", tets[0]);
	testvariable = ft_12arr(tets, n * 4, 4);
	i = -1;
	printf("Unzeroed tets:\n");
	j = -1;
	while (++j < n)
	{
		while (++i < 4)
			printf(" %d ", testvariable[j][i]);
		printf("\n");
		i = -1;
	}
	testvariable = fillit(testvariable, n);
	i = -1;
	j = -1;
	printf("Cleared tets:\n");
	while (++j < n)
	{
		while (++i < 4)
			printf(" %d ", testvariable[j][i]);
		printf("\n");
		i = -1;
	}
//	printf("\nIncremented tet[2]:");
//	increment_tet(testvariable[2], 4);
//	i = -1;
//	while (++i < 4)
//		printf(" %d ", testvariable[2][i]);
//	printf("\nTwice incremented tet[2]:");
//	increment_tet(testvariable[2], 4);
//	i = -1;
//	while (++i < 4)
//		printf(" %d ", testvariable[2][i]);
	printf("\n");
	return (0);
}
