/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 10:22:50 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/31 13:57:43 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static	int	*valid_tets(void)
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

static	int	*store_check(int fd, int *actual)
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

static	int	initial_check(int fd, char buffer, int hash, int pos)
{
	while (read(fd, &buffer, 1) != 0)
	{
		pos++;
		if (pos % 5 != 0 && pos != 21)
		{
			if (buffer != '.' && buffer != '#')
				return (0);
			if (buffer == '#')
				hash++;
		}
		else
		{
			if (buffer != '\n')
				return (0);
		}
		if (pos == 21)
		{
			if (hash != 4)
				return (0);
			pos = 0;
			hash = 0;
		}
	}
	return (1);
}

static	int	*count(int fd, int *n, char **argv)
{
	char	buffer;
	int		pos;

	pos = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		pos++;
		if (pos == 21)
		{
			(*n)++;
			pos = 0;
		}
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (initial_check(fd, 'a', 0, 0) == 0)
		return (NULL);
	else
		return ((int *)malloc((*n * 4 + 1) * sizeof(int)));
}

int			*validate(int *n, char **argv)
{
	int	fd;
	int	*arr;

	fd = open(argv[1], O_RDONLY);
	arr = count(fd, n, argv);
	if (arr == NULL)
		return (arr);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	return (store_check(fd, arr));
}
