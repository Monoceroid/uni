/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:59:11 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/31 13:38:03 by wtaylor          ###   ########.fr       */
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

int		**fillit(int **a, int n)
{
	int	l;
	int	init_l;

	l = 4;
	init_l = l;
	while (l * l < 4 * n)
		l++;
	printf("a[0][1]: %d, l: %d, init_l: %d, n: %d\n", a[0][1], l, init_l, n);
	upsize_all(a, l, init_l, n);
	printf("a[0][1]: %d, n: %d, l: %d\n", a[0][1], n, l);
	zero_all(a, n, l);
	return (a);
}

int		main(int argc, char **argv)
{
	int		*tets;
	int		n;
	int		**testvariable;

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
	printf("Unzeroed tet[2][1]: %d\n", testvariable[2][1]);
	testvariable = fillit(testvariable, n);
	printf("Zeroed tet[2][1]: %d\n", testvariable[2][1]);
	return (0);
}
