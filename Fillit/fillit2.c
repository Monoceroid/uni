/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:59:11 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/25 12:12:50 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

typedef	struct	s_tet
{
		int	cdif1;
		int cdif2;
		int cdif3;
}				c_tet;

c_tet	tet_struct(int *a, int l)
{
	c_tet	tet;
	
	tet.cdif1 = ((a[1] - 1) % l) - ((a[0] - 1) % l);
	tet.cdif2 = ((a[2] - 1) % l) - ((a[1] - 1) % l);	
	tet.cdif3 = ((a[3] - 1) % l) - ((a[2] - 1) % l);
	return (tet);
}

void	zero_tet(int *a, int l)
{
	c_tet	old_struct;

	old_struct = tet_struct(a, l);
	printf("Old_struct cdif1: %d\n", old_struct.cdif1);
	while (a[0] > 1)
	{
		a[0]--;
		a[1]--;
		a[2]--;
		a[3]--;
	}
	while (tet_struct(a, 4).cdif1 != old_struct.cdif1 || tet_struct(a, 4).cdif2 != 
			old_struct.cdif2 || tet_struct(a, 4).cdif3 != old_struct.cdif3 )
	{
		a[0]++;
		a[1]++;
		a[2]++;
		a[3]++;
	}
}
/*
void	zero_all(int **a, int n, int l)
{
	int	i;

	i = -1;
	while (++i < n)
		zero_tet(*a++);
}

int	**fillit(int **a, int n)
{
	int	l;

	l = 4;
	while (l * l < 4 * n)
		l++;
	zero_all(a, n, l);
}
*/
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

int	main(int argc, char **argv)
{
	int		fd;
	int		*arr;
	int		*tets;
	int		n;

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
//	fillit(tets, n);
//	printf("%d\n", tets[16]);
	printf("Number of tets: %d\n", n);
//	printf("cdif1: %d\n", (tet_struct(tets, 4)).cdif1);
	zero_tet(tets, 4);	
	printf("Zeroed tet element: %d\n", tets[0]);
	close(fd);
	return (0);
}
