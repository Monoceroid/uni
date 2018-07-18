/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:59:11 by wtaylor           #+#    #+#             */
/*   Updated: 2018/07/18 15:15:30 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int	*valid_tets(void)
{
	char	*s;
	int	*tets;
	int	i = 0;

	s = "1,2,3,4,1,5,9,13,1,2,3,7,2,6,9,10,1,5,6,7,1,2,5,9,1,5,6,10,2,3,"
		"5,6,1,2,3,6,2,5,6,10,2,5,6,7,1,5,6,9,1,2,5,6,2,5,6,9,1,2,6,7,1,"
		"2,3,5,1,2,6,10,3,5,6,7,1,5,9,10,";
	printf("%s", s);
//	tets = ft_arrstr(s, ',', 76);
//	while (i < 76)
//		printf("%d, ", *tets++);
	return (tets);
}

//int	*store_check(int fd, int *arr)
//{
//	char	buffer;
//	int		pos;
//	int		valid[19][4];
//
//	pos = 0;
//	valid = ;
//	while (read(fd, &buffer, 1) != 0)
//	{
//		pos++;
//		if (buffer == '#')
//			*arr++ = pos;
//		if (pos == 16)
//			pos = 0;
//	}
//}

int	*check_count(int fd)
{
	char	buffer;
	int		pos;
	int		lines;
	int		*arr;

	buffer = 'a';
	pos = 0;
	lines = 0;
	while (read(fd, &buffer, 1) != 0)
	{
//		printf("Buffer: %c %d\n", buffer, buffer);
		pos++;
//		printf("Position: %d\n", pos);
		if (pos % 5 != 0 && pos != 21)
		{
			if (buffer != '.' && buffer != '#')
				return (NULL);
		}
		else
		{
			if (buffer != '\n')
				return (NULL);
		}
		if (pos == 21)
		{
			lines += 4;
//			printf("Lines: %d\n", lines);
			pos = 0;
		}
	}
//	printf("%d\n", lines);
	arr = (int *)malloc(lines * sizeof(int));
	return (arr);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		*arr;
	int		*tets;

	if (argc != 2)
	{
		ft_putstr("usage: fillit file_name");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if ((arr = check_count(fd)) == NULL)
	{
		ft_putstr("error");
		ft_putchar('\n');
		return (0);
	}
	tets = valid_tets();
//	if ((tets = store_check(fd, arr)) == NULL)
//	{
//		ft_putstr("error");
//		ft_putchar('\n');
//		return (0);
//	}
	close(fd);
	return (0);
}
