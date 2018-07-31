/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:59:11 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/31 10:10:27 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int	**fillit(int **a, int n)
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

int	*valid_tets(void)
{
	char	*s;
	int		*tets;

	s = "1,2,3,4,1,5,9,13,1,2,3,7,2,6,9,10,1,5,6,7,1,2,5,9,1,5,6,10,"
		"2,3,5,6,1,2,3,6,2,5,6,10,2,5,6,7,1,5,6,9,1,2,5,6,2,5,6,9,"
		"1,2,6,7,1,2,3,5,1,2,6,10,3,5,6,7,1,5,9,10,5,6,7,8,9,10,11,12,"
		"13,14,15,16,2,6,10,14,3,7,11,15,4,8,12,16,2,3,4,8,5,6,7,11,6,7,8,12,"
		"9,10,11,15,10,11,12,16,3,7,10,11,4,8,11,12,6,10,13,14,7,11,13,15,"
		"8,12,15,16,2,6,7,8,5,9,10,11,6,10,11,12,9,13,14,15,10,14,15,16,"
		"2,3,6,10,3,4,7,11,5,6,9,13,6,7,10,14,7,8,11,15,2,3,4,6,5,6,7,9,6,7,8,"
		"10,9,10,11,13,10,11,12,14,2,3,7,11,3,4,8,12,5,6,10,14,6,7,11,15,7,8,"
		"12,16,4,6,7,8,7,9,10,11,8,10,11,12,11,13,14,15,12,14,15,16,2,6,10,"
		"11,3,7,11,12,5,9,13,14,6,10,14,15,7,11,15,16,2,6,7,11,3,7,8,12,5,9,"
		"10,14,6,10,11,15,7,11,12,16,3,4,6,7,6,7,9,10,7,8,10,11,10,11,13,14,"
		"11,12,14,15,3,6,7,10,4,7,8,11,6,9,10,13,7,10,11,14,8,11,12,15,2,3,7,"
		"8,5,6,10,11,6,7,11,12,9,10,14,15,10,11,15,16,2,3,4,7,5,6,7,10,6,7,8,"
		"11,9,10,11,14,10,11,12,15,3,6,7,11,4,7,8,12,6,9,10,14,7,10,11,15,8,"
		"11,12,16,3,6,7,8,6,9,10,11,7,10,11,12,10,13,14,15,11,14,15,16,2,6,7,"
		"10,3,7,8,11,5,9,10,13,6,10,11,14,7,11,12,15,2,3,6,7,3,4,7,8,5,6,9,"
		"10,6,7,10,11,7,8,11,12,9,10,13,14,10,11,14,15,11,12,15,16,0";
	tets = ft_arrstr(s, ',', 77);
	return (tets);
}

int	*store_check(int fd, int *actual)
{
	char	buffer;
	int		pos;
	int		*valid;
	int		acount;
	int		vcount;

	pos = 1;
	acount = 0;
	vcount = 0;
	valid = valid_tets();
	while (read(fd, &buffer, 1) != 0)
	{
		if (buffer == '#')
		{
			*actual++ = pos++;
			acount++;
		}
		if (buffer == '.')
			pos++;
		if (pos == 17)
			pos = 1;
	}
	actual -= acount;
	acount = 0;
	while (*actual != 0)
	{
		pos = 0;
		while (*valid != 0)
		{
			if (*actual == *valid && *(actual + 1) ==
					*(valid + 1) && *(actual + 2) == *(valid + 2)
					&& *(actual + 3) == *(valid + 3))
			{
				actual += 4;
				acount += 4;
				pos = 1;
				break ;
			}
			else
			{
				valid += 4;
				vcount += 4;
			}
		}
		if (pos != 1)
			return (NULL);
		valid -= vcount;
		vcount = 0;
	}
	actual -= acount;
	return (actual);
}

int	*check_count(int fd, int *n)
{
	char	buffer;
	int		pos;
	int		lines;
	int		*arr;
	int		hash;

	buffer = 'a';
	hash = 0;
	pos = 0;
	lines = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		pos++;
		if (pos % 5 != 0 && pos != 21)
		{
			if (buffer != '.' && buffer != '#')
				return (NULL);
			if (buffer == '#')
				hash++;
		}
		else
		{
			if (buffer != '\n')
				return (NULL);
		}
		if (pos == 21)
		{
			lines += 4;
			if (hash != 4)
				return (NULL);
			pos = 0;
			hash = 0;
		}
	}
	arr = (int *)malloc((lines + 1) * sizeof(int));
	*n = lines / 4;
	return (arr);
}

/*
**	This is a test comment.
*/

int	main(int argc, char **argv)
{
	int		fd;
	int		*arr;
	int		*tets;
	int		n;
	int		**testvariable;

	if (argc != 2)
	{
		ft_putstr("usage: fillit file_name");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if ((arr = check_count(fd, &n)) == NULL)
	{
		ft_putstr("error");
		ft_putchar('\n');
		return (0);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if ((tets = store_check(fd, arr)) == NULL)
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
	close(fd);
	return (0);
}
